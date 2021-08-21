#include <EEPROM.h>
int period = 2;                // (300 seconds = 5 minutes)
int fanSampleRate = 10;          // Combien de millisecondes entre la prise de mesure de la vitesse du vent (doit être suffisamment petit pour capturer le pic de la forme d'onde analogique)
int fanPin = A5;
int highest = 0;      // Suivi de la vitesse du vent la plus élevée sur une période
int seconds = 0;     // Enregistre le nombre de secondes écoulées dans une période
int promAddr = 0;    // Index actuel dans la mémoire EEPROM
String wind;


/*********************************************************************************
 *timer1_init ()                                                                 *
  *
  * Configure les registres pour utiliser TIMER 1 qui sera                       *
  * utilisé pour appeler un gestionnaire d'interruption une fois par seconde     *
  * (Suppose qu'Arduino Uno est basé sur ATMEGA328)                              *
 **********************************************************************************/
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
  
  if (newReading > highest)
    highest = newReading;
 
  return String(highest);
}


/********************************************************
 * setup()
 * 
 * Start-up initializations.
 ********************************************************/
void setup() {
  pinMode(A5,INPUT);
  Serial.begin(9600);
  timer1_init(); 
}


/********************************************************
 * loop()
 *
 * Main program loop.
 ********************************************************/
void loop() {
  wind = readWindSpeed();

  
    Serial.print("Highest: ");
    Serial.println(wind);

  delay(fanSampleRate); // Time in between taking readings from anemometer (fan)
}
