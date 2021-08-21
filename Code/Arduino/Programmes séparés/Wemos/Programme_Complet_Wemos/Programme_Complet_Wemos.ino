#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SFE_BMP180.h>
#include "indexx.h"
#include "FirebaseArduino.h"

#define FIREBASE_HOST "arduino-webserver-esisba.firebaseio.com"                          // the project name address from firebase id
#define FIREBASE_AUTH "3SkXnLioY1migi1LxrD5d7YX7g5Z2ErPM4rml4jw"            // the secret key generated from firebase

#define WIFI_SSID "D-Link"                                             // input your home or public wifi name 
#define WIFI_PASSWORD "30061969"                                    //password of wifi ssid

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;
//

AsyncWebServer server(80);


DHT dht(D8,DHT11);
LiquidCrystal_I2C lcd (0x3F, 16, 2);
const int wspin = A0;
int wsvalue;
const char* ws;
SFE_BMP180 bmp180;



float t=0.0;
float h=0.0;

float hum;
float temp;
String water;
float tempF;
float pres;
float ptdre;
double ptr;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float readPRESSURE() {
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
          Serial.print("Pressure: ");
          Serial.print(P);
          Serial.println(" hPa");

          Serial.print("Temperature: ");
          Serial.print(T);
          Serial.println(" C");
        }
      }
    }
  }
  if (isnan(P)) {
    Serial.println("Failed to read from bmp180 sensor!");
    Serial.println(String(P));
    return -1;
  }
  else {
    Serial.println(P);
    return P;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float readDHTTemperature() {
  float t = dht.readTemperature();
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    Serial.println(String(t));
    return -1;
  }
  else {
    Serial.println(t);
    return t;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float readDHTTemperatureFahrenheit() {
  float t = dht.readTemperature(true);
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    Serial.println(String(t));
    return -1;
  }
  else {
    Serial.println(t);
    return t;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
String readwatersenser() {
// Begin loop WS
   wsvalue = analogRead(wspin);
  if (wsvalue<=480){ 
    Serial.println("Water level: 0mm - Empty!");
    Serial.println(String(wsvalue));
    ws = "0mm - Empty!"; 
  }
  else if (wsvalue>480 && wsvalue<=530){ 
    Serial.println("Water level: 0mm to 5mm");
    Serial.println(String(wsvalue));
    ws = "0-5mm"; 
  }
  else if (wsvalue>530 && wsvalue<=615){ 
    Serial.println("Water level: 5mm to 10mm");
    Serial.println(String(wsvalue));
    ws = "5-10mm"; 
  }
  else if (wsvalue>615 && wsvalue<=660){ 
    Serial.println("Water level: 10mm to 15mm");
    Serial.println(String(wsvalue));
    ws = "10-15mm"; 
  } 
  else if (wsvalue>660 && wsvalue<=680){ 
    Serial.println("Water level: 15mm to 20mm");
    Serial.println(String(wsvalue));
    ws = "15-20mm"; 
  }
  else if (wsvalue>680 && wsvalue<=690){ 
    Serial.println("Water level: 20mm to 25mm");
    Serial.println(String(wsvalue));
    ws = "20-25mm"; 
  }
  else if (wsvalue>690 && wsvalue<=700){ 
    Serial.println("Water level: 25mm to 30mm");
    Serial.println(String(wsvalue));
    ws = "25-30mm"; 
  }
  else if (wsvalue>700 && wsvalue<=705){ 
    Serial.println("Water level: 30mm to 35mm");
    Serial.println(String(wsvalue));
    ws = "30-35mm"; 
  }
  else if (wsvalue>705){ 
    Serial.println("Water level: 35mm to 40mm");
    Serial.println(String(wsvalue));
    ws = "35-40mm"; 
  }
  if (isnan(wsvalue)) {
    Serial.println("Failed to read from Water sensor!");
    return "--";
  }
  else {
    Serial.println(ws);
    return String(ws);
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float readDHTHumidity() {
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    Serial.println(String(h));
    return -1;
  }
  else {
    Serial.println(h);
    return h;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float readpointderosee () {
   double Tr = (pow((dht.readHumidity()/100),0.125))*(112+(0.9*dht.readTemperature()))+(0.1*dht.readTemperature())-112;
   Serial.println ("Point de rosee : ");
   Serial.println (String(Tr));
  if (isnan(Tr)) {
    Serial.println("Failed to read pointderosee");
    Serial.println(String(Tr));
    return -1;
  }
  else {
    Serial.println(Tr);
    return Tr;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  dht.begin();


  server.begin();
  //WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                              // connect to firebase
  
  dht.begin();
  bool success = bmp180.begin();
  if (success) {
    Serial.println("BMP180 init success");
  }


  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html_2 );
  });

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(temp).c_str());
  });
  
  server.on("/temperatureF", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(tempF).c_str());
  });
  
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(hum).c_str());
  });

  server.on("/whater_lavel", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(water).c_str());
  });
  
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(pres).c_str());
  });
  
  server.on("/point_de_rose", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(ptdre).c_str());
  });
  

  lcd.begin();
  lcd.clear(); 


  // Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(3600);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  temp=readDHTTemperature(); 
  hum=readDHTHumidity();
  water = readwatersenser();
  tempF= readDHTTemperatureFahrenheit();
  pres= readPRESSURE();
  ptdre= readpointderosee();

////////////////////////////// Begin loop LCD
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
  lcd.setCursor (2,1);
  lcd.print (" "+ String(water) +" ");  
  delay (2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("Point de rosee : ");
  lcd.setCursor (4,1);
  lcd.print (" "+ String(ptdre) +" ");  
////////////////////////////// End loop LCD

////////////////////////////// Begin loop date + time
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
////////////////////////////// End loop date + time


////////////////////////////// Begin loop Firebase 
  if (isnan(hum) || isnan(temp) || isnan(tempF) || isnan(pres) || isnan(ptdre)) {                                                // Check if any reads failed and exit early (to try again).
    Serial.println(F("Failed to read from sensors!"));
    return;
  }  
  
  Serial.print("Humidity: ");  Serial.print(hum);
  String fireHumid = String(hum) + String("%");                                         //convert integer humidity to string humidity 
  Serial.print("%  Temperature: ");  Serial.print(temp);  Serial.println("Â°C ");
  String fireTemp = String(temp) + String("Â°C");                                                     //convert integer temperature to string temperature
  Serial.print("Water: ");  Serial.print(water);
  String fireWater = String(water) + String("%");                                         //convert integer humidity to string humidity 
  Serial.print("%  TemperatureF: ");  Serial.print(tempF);  Serial.println("Â°C ");
  String fireTempF = String(tempF) + String("Â°C");
  Serial.print("Pressure: ");  Serial.print(pres);
  String firePres = String(pres) + String("%");                                         //convert integer humidity to string humidity 
  Serial.print("%  Point de rosee: ");  Serial.print(ptdre);  Serial.println("Â°C ");
  String firePtdre = String(ptdre) + String("Â°C");
  
  Firebase.pushString("/DHT11/Humidity", fireHumid);                                  //setup path and send readings
  Firebase.pushString("/DHT11/Temperature", fireTemp);                                //setup path and send readings
  Firebase.pushString("/DHT11/WaterLevel", fireWater);                                  //setup path and send readings
  Firebase.pushString("/DHT11/TemperatureF", fireTempF);                                //setup path and send readings
  Firebase.pushString("/DHT11/Pressure", firePres);                                  //setup path and send readings
  Firebase.pushString("/DHT11/PointDeRosee", firePtdre);                                //setup path and send readings
////////////////////////////// End loop Firebase
  
}
