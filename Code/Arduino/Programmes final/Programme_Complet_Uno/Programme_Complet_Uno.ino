/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lib
   #include <DHT.h>
   #include <Wire.h>
   #include <SFE_BMP180.h>
   #include <EEPROM.h>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declarations

//DHT
   DHT dht(8,DHT11);

//WS
   const int wspin = A4;
   int wsvalue;
   const char* ws;

//BMP
   SFE_BMP180 bmp180;

//Capteur Pluie
   const int rainpin = 7;
   const char* caprain;

//Wind Speed
  int period = 15;                // (300 seconds = 5 minutes)
  int fanSampleRate = 10;          // Combien de millisecondes entre la prise de mesure de la vitesse du vent (doit être suffisamment petit pour capturer le pic de la forme d'onde analogique)
  int fanPin = A0;
  int highest = 0;      // Suivi de la vitesse du vent la plus élevée sur une période
  int seconds = 0;     // Enregistre le nombre de secondes écoulées dans une période
  int promAddr = 0;    // Index actuel dans la mémoire EEPROM

//Values
   int hum;      //DHT11
   float temp;     //DHT11
   String water;   //WS
   float tempF;    //DHT11
   int pres;     //BMP
   float ptdre;    //DHT11
   String rain;   //Capteur de pluie
   String wind;     //Anemometre

//Serial Connection
   String message;
   char mystr[63]; //String data
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int readPRESSURE() {
  char status;
  double T, P;
  bool success = false;

  status = bmp180.startTemperature();

  if (status != 0) {
    delay(1000);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);

        if (status != 0) {
          /*
          Serial.print("Pressure: ");
          Serial.print(P);
          Serial.println(" hPa");

          Serial.print("Temperature: ");
          Serial.print(T);
          Serial.println(" C");
          *//*
        }
      }
    }
  }
  if (isnan(P)) {
    //Serial.println("Failed to read from bmp180 sensor!");
    return -1;
  }
  else {
    return P;
  }
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float readDHTTemperature() {
  float t = dht.readTemperature();
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    return -1;
  }
  else {
    return t;
  }
}

float readDHTTemperatureFahrenheit() {
  float tf = dht.readTemperature(true);
  if (isnan(tf)) {    
    Serial.println("Failed to read from DHT sensor!");
    return -1;
  }
  else {
    return tf;
  }
}

int readDHTHumidity() {
  int h = dht.readHumidity();
  if (isnan(h)) {
    return -1;
  }
  else {
    return h;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
String readWaterSensor() {
  wsvalue= analogRead(wspin);
  if (isnan(wsvalue)) {
    return "--";
  }
  else {
    if (wsvalue<530){ 
       ws = "0";
    }
    else if (wsvalue>=530 && wsvalue<550){ 
       ws = "10";
    }
    else if (wsvalue>=550 && wsvalue<580){ 
       ws = "20";
    } 
    else if (wsvalue>=580 && wsvalue<610){ 
       ws = "30";
    }
    else if (wsvalue>=610){ 
       ws = "40"; 
    }
    
    return String(ws);
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float readDewPoint() {
   double Tr = (pow((dht.readHumidity()/100),0.125))*(112+(0.9*dht.readTemperature()))+(0.1*dht.readTemperature())-112;
  if (isnan(Tr)) {
    return -1;
  }
  else {
    return Tr;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
String readCapRain() {
  if (isnan(digitalRead(rainpin))) {    
    return "--";
  }
  else {
    if(digitalRead(rainpin) == LOW)
    {
      caprain = "raining";
      delay(10);
     }
     else
     {
       caprain = "no rain";
       delay(10);
     }
     return String(caprain);
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void timer1_init() {
// Utilisé le calculateur de minuterie Arduino à http://www.8bit-era.cz/arduino-timer-interrupts-calculator.html pour générer ce code  
  // TIMER 1 for interrupt frequency 1 Hz:
  cli(); // stop interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 1 Hz increments
  OCR1A = 62499; // = 16000000 / (256 * 1) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 256 prescaler
  TCCR1B |= (1 << CS12) | (0 << CS11) | (0 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // allow interrupts 
}


/********************************************************
 * Interrupt Service Routine (Timer 1)
 *
 * This is called by Timer 1 once a second.
 ********************************************************/
ISR(TIMER1_COMPA_vect) {         // timer compare interrupt service routine

 // Cette section incrémente le compteur des secondes à chaque fois que le gestionnaire d'interruption est appelé.
   // Une fois que le nombre de secondes atteint la durée de la période, nous exécutons ce bloc de code et le réinitialisons.
  seconds++;
  if (seconds >= period) {
    seconds = 0;

    EEPROM.write(promAddr++, highest); // Ecrire la vitesse du vent la plus élevée de la période dans l'EEPROM
    highest = 0;
  }
}

String readWindSpeed() {  
  int newReading = analogRead(fanPin);
  if (newReading > highest){
    highest = newReading ;
  }
 
  return String(highest);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  
  dht.begin();
  
  pinMode(rainpin, INPUT);
  
  pinMode(wspin,INPUT);

  pinMode(fanPin,INPUT); //windpin
  timer1_init();

  /*
  bool success = bmp180.begin();
  if (success) {
    //Serial.println("BMP180 init success");
  }
  */

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

  temp  = readDHTTemperature(); 
  tempF = readDHTTemperatureFahrenheit();
  hum   = readDHTHumidity();
  ptdre = readDewPoint();
  water = readWaterSensor();
  rain  = readCapRain();
  wind  = readWindSpeed();
  //pres= readPRESSURE();
  pres  = 1235;
  
  message = String(temp)+"/"+String(hum)+"/"+String(water)+"/"+String(tempF)+"/"+String(pres)+"/"+String(ptdre)+"/"+String(rain)+"/"+String(wind)+"/";
  //Serial.println (String(message));
  message.toCharArray(mystr,63);
  Serial.write(mystr,63);
  Serial.println (" ");

  delay(15000);

}
