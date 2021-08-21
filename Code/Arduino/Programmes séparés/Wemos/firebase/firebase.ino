#include "ESP8266WiFi.h"                                                    // esp8266 library
#include "FirebaseArduino.h"                                                // firebase library
                                                          // dht11 temperature and humidity sensor library

#define FIREBASE_HOST "arduino-webserver-esisba.firebaseio.com"                          // the project name address from firebase id
#define FIREBASE_AUTH "3SkXnLioY1migi1LxrD5d7YX7g5Z2ErPM4rml4jw"            // the secret key generated from firebase

#define WIFI_SSID "D-Link"                                             // input your home or public wifi name 
#define WIFI_PASSWORD "30061969"                                    //password of wifi ssid
 
//const char* ssid     = "D-Link";
//const char* password = "30061969";

  int tim = 0;
  float h = 0;                                            // Reading temperature or humidity takes about 250 milliseconds!
  float t = 0;                                           // Read temperature as Celsius (the default)
    

void setup() {
  
  Serial.begin(9600);
  delay(1000);                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                              // connect to firebase
                                                                 //Start reading dht sensor
}

void loop() { 
    h++;
    t++;
    // t et h représentent les données qui faut récuperer du capteur
  if (isnan(h) || isnan(t)) {                                                // Check if any reads failed and exit early (to try again).
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print("Humidity: ");  Serial.print(h);
  String fireHumid = String(h) + String("%");                                         //convert integer humidity to string humidity 
  Serial.print("%  Temperature: ");  Serial.print(t);  Serial.println("Â°C ");
  String fireTemp = String(t) + String("Â°C");                                                     //convert integer temperature to string temperature
  delay(4000);
  Serial.print("time:  ");
  Serial.println(tim);
  String path ="";
  path = "/" + String ("01") + "/" + String (tim);
  Serial.print("path:  ");
  Serial.println(path);
   
  
  Firebase.pushString(path, fireHumid);                                  //setup path and send readings
  Firebase.pushString(path, fireTemp);                                    //setup path and send readings
  tim += 4;
   
}

/*
#include "ESP8266WiFi.h"                                                    // esp8266 library
#include "FirebaseArduino.h"                                                // firebase library
                                                          // dht11 temperature and humidity sensor library

#define FIREBASE_HOST "arduino-webserver-esisba.firebaseio.com"                          // the project name address from firebase id
#define FIREBASE_AUTH "3SkXnLioY1migi1LxrD5d7YX7g5Z2ErPM4rml4jw"            // the secret key generated from firebase

#define WIFI_SSID "D-Link"                                             // input your home or public wifi name 
#define WIFI_PASSWORD "30061969"                                    //password of wifi ssid
 
  float h = 0;                                              // Reading temperature or humidity takes about 250 milliseconds!
  float t = 0;                                                     

void setup() {
  Serial.begin(9600);
  delay(1000);                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                              // connect to firebase
}

void loop() {
  // Read temperature as Celsius (the default)

    t++;
    h++;
    
  if (isnan(h) || isnan(t)) {                                                // Check if any reads failed and exit early (to try again).
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print("Humidity: ");  Serial.print(h);
  String fireHumid = String(h) + String("%");                                         //convert integer humidity to string humidity 
  Serial.print("%  Temperature: ");  Serial.print(t);  Serial.println("Â°C ");
  String fireTemp = String(t) + String("Â°C");                                                     //convert integer temperature to string temperature
  delay(4000);
  
  Firebase.pushString("/DHT11/Humidity", fireHumid);                                  //setup path and send readings
  Firebase.pushString("/DHT11/Temperature", fireTemp);                                //setup path and send readings
   
}
*/
