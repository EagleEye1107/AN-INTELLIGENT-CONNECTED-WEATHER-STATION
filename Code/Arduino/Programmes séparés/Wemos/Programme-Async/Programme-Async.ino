/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//  PS : La température est prise du DHT11 et non pas du BMP180 (moins de précision pour le DHT11) //
//  à la fin de la réalisation du projet switch temp form DHT11 to BMP180                          //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////


//Begin Librairies
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
#include <ESP8266WiFi.h>
//#include <ESP8266WebServer.h>
//#include <Adafruit_Sensor.h>
//#include <LiquidCrystal_I2C.h>
//#include <Wire.h>
//#include <DHTesp.h>
//#include <SFE_BMP180.h>
#include <DHT.h>

#include "index.h"
//End Librairies

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Begin Declarations

//Web-server
const char* ssid     = "D-Link";
const char* password = "30061969";
// Set web server port number to 80
AsyncWebServer server(80);
// Variable to store the HTTP request
String header;

//LCD
//LiquidCrystal_I2C lcd (0x3F, 16, 2);

//DHT
DHT dht(D8,DHT11);

String readDHTTemperature() {
  float t = dht.readTemperature();
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    Serial.println(String(t));
    return "--";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}
String readDHTHumidity() {
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    Serial.println(String(h));
    return "--";
  }
  else {
    Serial.println(h);
    return String(h);
  }
}
/*
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE"){
    return readDHTTemperature();
  }
  else if(var == "HUMIDITY"){
    return readDHTHumidity();
  }
  return String();
}
*/
void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}


void setup() {
// Begin setup DHT
  Serial.begin(9600);
  dht.begin();
// End setup DHT
  
//Begin Web Server  
   
  server.begin();
    //WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  //server.onNotFound(notFound);
  
  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html );
  });

  Serial.println (String(readDHTTemperature()));
  Serial.println (String(readDHTHumidity()));
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTTemperature().c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTHumidity().c_str());
  });
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  delay(10000);
  }
