#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SFE_BMP180.h>
#include "indexx.h"



const char* ssid     = "D-Link";
const char* password = "30061969";

AsyncWebServer server(80);






DHT dht(D8,DHT11);

LiquidCrystal_I2C lcd (0x3F, 16, 2);

const int wspin = A0;
int wsvalue;
const char* ws;

SFE_BMP180 bmp180;





float t=0.0;
float h=0.0;
String temp;
String tempF;
String pres;
String water;
String ptder;
String hum;

double ptr;




String readPRESSURE() {
  
// Begin loop BMP180
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
// End loop BMP180


  
  if (isnan(P)) {
    Serial.println("Failed to read from bmp180 sensor!");
    Serial.println(String(P));
    return "--";
  }
  else {
    Serial.println(P);
    return String(P);
  }
}

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

String readDHTTemperatureFahrenheit() {
  float t = dht.readTemperature(true);
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

// End loop WS

  if (isnan(wsvalue)) {
    Serial.println("Failed to read from Water sensor!");
    return "--";
  }
  else {
    Serial.println(ws);
    return String(ws);
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
  }}

String readpointderosee () {

// Begin Point de rosée
   double Tr = (pow((dht.readHumidity()/100),0.125))*(112+(0.9*dht.readTemperature()))+(0.1*dht.readTemperature())-112;
   Serial.println ("Point de rosee : ");
   Serial.println (String(Tr));
// End Point de rosée

  if (isnan(Tr)) {
    Serial.println("Failed to read pointderosee");
    Serial.println(String(Tr));
    return "--";
  }
  else {
    Serial.println(Tr);
    return String(Tr);
  }}

/*String processor(const String& var){
  //Serial.println(var);
  switch(var) {
      case 'TEMPERATURE' :
         return readDHTTemperature();
         break;
      case 'HUMIDITY' :
        return readDHTHumidity();
        break;
      case 'TEMPERATUREF' :
         return readDHTTemperatureFahrenheit();
         break;
      case 'WHATER_LAVEL' :
        return readwatersenser();
        break;
      case 'PRESSURE' :
         return readPRESSURE();
         break;
      case 'POINTDEROSEE' :
        return readpointderosee();
        break;
  }
  return String();
}

*/


void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(115200);
  dht.begin();


  server.begin();
  //WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println(WiFi.localIP());


  
  dht.begin();
  bool success = bmp180.begin();
  if (success) {
    Serial.println("BMP180 init success");
  }


  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html_2 );
  });

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", temp.c_str());
  });
  
  server.on("/temperatureF", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", tempF.c_str());
  });
  
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", hum.c_str());
  });

  server.on("/whater_lavel", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", water.c_str());
  });
  
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", pres.c_str());
  });
  
  server.on("/point_de_rose", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", ptder.c_str());
  });
  

  lcd.begin();
  lcd.clear(); 



}



void loop() {


  temp=readDHTTemperature(); 
  hum=readDHTHumidity();
  water = readwatersenser();
  tempF= readDHTTemperatureFahrenheit();
  pres= readPRESSURE();
  ptder= readpointderosee();
  delay(1000);











  // Begin loop LCD
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("TEMP : ");
  lcd.setCursor (0,1);
  lcd.print (""+ readDHTTemperature() +" C- "+ readDHTTemperatureFahrenheit() +" F");
  // lcd.print (""+ String(T) +" C- "+ String((T*(9/5))+32)) +" F"); //BMP180
  delay (2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("HUMIDITY : ");
  lcd.setCursor (4,1);
  lcd.print (" " + readDHTHumidity() +"%");
  delay (2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("PRESSURE : ");
  lcd.setCursor (4,1);
  lcd.print (" " + readPRESSURE() +"hPa");  
  delay (2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("WATER LEVEL : ");
  lcd.setCursor (2,1);
  lcd.print (" "+ readwatersenser() +" ");  
  delay (2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("Point de rosee : ");
  lcd.setCursor (4,1);
  lcd.print (" "+ readpointderosee() +" ");  
  delay (2000);
  // End loop LCD

}
