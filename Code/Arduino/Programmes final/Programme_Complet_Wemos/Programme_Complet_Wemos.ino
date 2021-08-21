#include <ESPAsyncWebServer.h>  // 
#include <ESPAsyncTCP.h>        //
#include <ESP8266WiFi.h>        //
//#include <time.h>               //
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Wire.h>               // This library allows you to communicate with I2C / TWI devices
#include <LiquidCrystal_I2C.h>  // LCD_I2C library for the communication Arduino --> I2C --> LCD
#include "index.h"              // the main page for our web application
#include "report.h"             // the report page for our web application 
#include "FirebaseArduino.h"    // Firebase library for arduino communication with firebase

#define FIREBASE_HOST "arduino-webserver-esisba.firebaseio.com"        // the project name address from firebase id
#define FIREBASE_AUTH "3SkXnLioY1migi1LxrD5d7YX7g5Z2ErPM4rml4jw"       // the secret key generated from firebase

#define WIFI_SSID "BAAHMED"            // input your home or public wifi name 
#define WIFI_PASSWORD "AhmedDell#%*"      // password of wifi ssid

/*
// Variables for date and time
String dayStamp;
String timeStamp;
int timezone = 1 * 3600;
int dst = 0;
//

*/
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;
//


// port : 80 for the web server communication
AsyncWebServer server(80);

// LCD initiallization
LiquidCrystal_I2C lcd (0x3F, 16, 2);
// 16 and 2 : our LCD 16x2 is composed of 16 columns and 2 lines
// 0x3F : our I2C address to communicate with the LCD


// serial communication variable
String mess;

// weather variables (values)
String hum;    // humidity
String temp;   // temperature
String water;  // water level
String tempF;  // temperature Fahrenheit
String pres;   // pressure
String ptdre;  // dew point
String rain;   // rain
String wind;   // wind speed

// path variables
String pathDATA;
String pathLastValue;

// weather icon variables
float p;     // pressure value
float t;     // temperature value
String r;    // rain value
String icon; // our icon signification

//ALerte tempete buzzer
#define buzzer D8        
int frequence = 494;     

// variable of led action
int ledPin = D2;
String fireStatus; 
String pathAction = "/actions/action1/state";


/*Since this is a route not found handling function, we will return to the client a 404 HTTP response code. 
As content, we will return a plain text string with a message indicating that the content was not found.*/
void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}


void setup() {
  Serial.begin(9600);

/*
// config static IP
  IPAddress ip(192, 168, 1, 46); // where xx is the desired IP Address
  IPAddress gateway(192, 168, 1, 1); // set gateway to match your network
  Serial.print(F("Setting static ip to : "));
  Serial.println(ip);
  IPAddress subnet(255, 255, 255, 0); // set subnet mask to match your network
  WiFi.config(ip, gateway, subnet);
*/
  

  pinMode(ledPin, OUTPUT);
  
// connect to the web server
  server.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP());

// connect to firebase  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);      

// LCD communication 
  lcd.begin();
  lcd.clear(); 

// Upload <main, report> pages to the web server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html_2 );
  });

  server.on("/report", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html_report );
  });

  
// Sending sensor values to our web application
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(temp).c_str());               // sending temperature value
  });
  
  server.on("/temperatureF", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(tempF).c_str());              // sending temperature Fahrenheit value
  });
  
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(hum).c_str());                // sending humidity value
  });

  server.on("/water_level", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(water).c_str());              // sending water level value
  });
  
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(pres).c_str());               // sending pressure value
  });
  
  server.on("/dew_point", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(ptdre).c_str());              // sending dew point value
  });

  server.on("/rain", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(rain).c_str());               // sending rain value
  });

  server.on("/wind", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(wind).c_str());               // sending wind speed value
  });

/*
// Initialize a NTPClient to get time
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  Serial.println("\nWaiting for Internet time");

  while(!time(nullptr)){
     Serial.print("*");
     delay(1000);
  }
  Serial.println("\nTime response....OK");   
*/
  // Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(3600);
}


void loop() {
 
  char *X[8] ;
  int i = 0;
  mess="";
  char  message[255];
  
////////////////////////////// Begin serial communication  
Serial.println("begin serial communication");

  if (Serial.available() > 0) {
    // read the incoming byte:
    mess = Serial.readString ();
    delay (1000);
    // say what you got:
    Serial.print("I received: ");
    Serial.println(mess);

  //////////////////////////    
  mess.toCharArray(message, 255);
  Serial.println ("message :");
  Serial.println (message);
  
  Serial.println("start convertion");
  char *token = strtok(message , "/");
  Serial.println("while( token != NULL ) code begin");
  while( token != NULL ) {
    Serial.println("while( token != NULL ) code in");
    X [i]= token;
    i++;
    token = strtok(NULL, "/");
  }
  Serial.println("while( token != NULL ) code end");

  temp=X[0]; 
  hum=X[1];
  water = X[2];
  tempF= X[3];
  pres= X[4];
  ptdre= X[5];
  rain= X[6];
  wind= X[7];
      


////////////////////////////// Begin loop LCD
Serial.println("Begin loop LCD");

  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("TEMP : ");
  lcd.setCursor (0,1);
  lcd.print (""+ String(temp) +" C- "+ String(tempF) +" F");
  delay (2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("HUMIDITY : ");
  lcd.setCursor (4,1);
  lcd.print (" " + String(hum) +"%");
  delay (2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("PRESSURE : ");
  lcd.setCursor (4,1);
  lcd.print (" " + String(pres) +"hPa");  
  delay (2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("WATER LEVEL : ");
  lcd.setCursor (4,1);
  lcd.print (" "+ String(water) +" mm");  
  delay (2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("DEW POINT : ");
  lcd.setCursor (4,1);
  lcd.print (" "+ String(ptdre) +" ");
  delay (2000); 
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("RAIN : ");
  lcd.setCursor (2,1);
  lcd.print (""+ String(rain) +" ");
  delay (2000); 
  if (wind.toFloat() > 62){
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print ("WIND : ");
    lcd.setCursor (0,1);
    lcd.print (""+ String(wind) +" Km/h TEMPETE!");
    ////////////////////////////// Begin loop Alerte Tempete//////////////////////////////////////////////////////////////////
       for (int i = 0; i < 8; i++)
       {
         tone(buzzer, frequence, 500);
         delay (100);
       }
    ////////////////////////////// End loop Alerte Tempete//////////////////////////////////////////////////////////////////
  }
  else {
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print ("WIND : ");
    lcd.setCursor (4,1);
    lcd.print (""+ String(wind) +" Km/h");
  }
  
Serial.println("end loop LCD");  
////////////////////////////// End loop LCD

////////////////////////////// Begin loop date + time
  Serial.println("Begin loop date + time");
  
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }
  // The formattedDate comes with the following format:
  // 2018-05-28T16:00:13Z
  // We need to extract date and time
  formattedDate = timeClient.getFormattedDate();
  Serial.println(formattedDate);

  // Extract date
  int splitT = formattedDate.indexOf("T");
  dayStamp = formattedDate.substring(0, splitT);
  Serial.print("DATE: ");
  Serial.println(dayStamp);
  // Extract time
  timeStamp = formattedDate.substring(splitT+1, formattedDate.length()-1);
  Serial.print("HOUR: ");
  Serial.println(timeStamp);

  Serial.println("end loop date + time");
////////////////////////////// End loop date + time

////////////////////////////// Begin loop Firebase  
Serial.println("begin loop Firebase");  
  
  Serial.print("Humidity : ");  
  Serial.print(hum);Serial.println(" %");
  String fireHumid = String(hum);                                          
  Serial.print("Temperature : ");  
  Serial.print(temp);Serial.println("°C");
  String fireTemp = String(temp);                                         
  Serial.print("Water : ");  
  Serial.print(water);Serial.println(" mm");
  String fireWater = String(water);                                       
  Serial.print("TemperatureF : ");  
  Serial.print(tempF);  Serial.println("°F");
  String fireTempF = String(tempF);
  Serial.print("Pressure : ");  
  Serial.print(pres);Serial.println(" pha");
  String firePres = String(pres);                                          
  Serial.print("Dew point : ");  
  Serial.println(ptdre);  
  String firePtdre = String(ptdre);
  Serial.print("Rain : ");  
  Serial.println(rain); 
  String fireRain = String(rain);
  Serial.print("Wind : ");  
  Serial.print(wind);Serial.println(" km/h");
  String fireWind = String(wind);       
  
  delay (1000);

  
  pathDATA = "/DATA/"+String(dayStamp)+"/"+String(timeStamp);
  Serial.println ("pathDATA");
  Serial.println (String(pathDATA));
//setup path and send readings 
  Firebase.pushString(pathDATA, fireTemp);                                  
  Firebase.pushString(pathDATA, fireTempF);                               
  Firebase.pushString(pathDATA, fireHumid);                               
  Firebase.pushString(pathDATA, fireWater);                               
  Firebase.pushString(pathDATA, firePres);                                
  Firebase.pushString(pathDATA, firePtdre);                               
  Firebase.pushString(pathDATA, fireRain);
  Firebase.pushString(pathDATA, fireWind); 


  pathLastValue = "last-val";
//setup path and send readings
  Firebase.setString(pathLastValue+"/temp", fireTemp);                                  
  Firebase.setString(pathLastValue+"/humidty", fireHumid);
  Firebase.setString(pathLastValue+"/pressure", firePres);
  Firebase.setString(pathLastValue+"/rain", fireWater);
  Firebase.setString(pathLastValue+"/wind", fireWind);

  Serial.println ("pathLastValue/temp");
  Serial.println (String(pathLastValue+"/temp"));

// weather icon
  p = pres.toFloat();
  t = temp.toFloat();
  r = rain;

  if (p < 1013){           // 1013 represente une pression standard 
   if (r == "rain"){
    if (t < 0){
      icon = "snow";
    }
    else{
      icon = "rain";
    }
   }
   else{
    icon = "cloud";
   }
  }
  else{
    icon = "sun";
  }
  Firebase.setString("/icons/weather", icon);
  

////////////////////////////// Begin loop Action//////////////////////////////////////////////////////////////////
  fireStatus = Firebase.getString(pathAction);
  Serial.println ("pathAction");
  Serial.println (String(pathAction));
  Serial.println ("fireStatus");  
  Serial.println(String(fireStatus));
  if (fireStatus == "ON")
   {                              
   Serial.println("Led Turned ON");      
   digitalWrite(ledPin, HIGH);                                  
   }
   else if (fireStatus == "OFF") 
    {    
    Serial.println("Led Turned OFF");
    digitalWrite(ledPin, LOW);
    }
////////////////////////////// End loop Action////////////////////////////////////////////////////////////////////////////////////////////////////////


Serial.println("end loop Firebase");  
////////////////////////////// End loop Firebase
    
  }else
  {
    Serial.print("Serial.available() = false ");
  }
  
Serial.println("end serial communication");
////////////////////////////// End serial communication
}
