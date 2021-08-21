/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//  PS : La température est prise du DHT11 et non pas du BMP180 (moins de précision pour le DHT11) //
//  à la fin de la réalisation du projet switch temp form DHT11 to BMP180                          //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////

//Begin Librairies
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
//#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
//#include <DHTesp.h>
#include <DHT.h>
#include <SFE_BMP180.h>
//End Librairies

// Begin Declarations
//Web-server
const char* ssid     = "D-Link";
const char* password = "30061969";

// Set web server port number to 80
AsyncWebServer server(80);

// Variable to store the HTTP request
String header;

//LCD
LiquidCrystal_I2C lcd (0x3F, 16, 2);

//DHT
DHT dht(D8,DHT11);

//Water Sensor
const int wspin = A0;
int wsvalue;
const char* ws;

//BMP180
SFE_BMP180 bmp180;


double ptr;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8">

    <style>
        body { text-align: center; font-family: \"Trebuchet MS\", Arial;}
        table { border-collapse: collapse; width:35%; margin-left:auto; margin-right:auto; }
        th { padding: 14px; background-color: #02ffff; color: rgb(0, 0, 0); }
        tr { border: 1px solid rgb(0, 0, 0); padding: 10px; }
        tr:hover { background-color: #000; color: aliceblue;}
        td { border: none; padding: 12px; }</style>
   
    <title>HTML page of web server</title></head>
<body><h1>arduino weather station wemos D1 </h1>


    <table><tr><th>MEASUREMENT</th><th>VALUE</th></tr>
        <tr><td>water lavel</td><td><span id="whater_lavel">%WHATER_LAVEL%</span>%</td></tr>
        <tr><td>Temp. Celsius</td><td><span id="temperature">%TEMPERATURE% °C</span></td></tr>
        <tr><td>Temp. Fahrenheit</td><td><span id="temperatureF">%TEMPERATUREF%</span>*F</td></tr>
        <tr><td>Pressure</td><td><span id="pressure">%PRESSURE%</span>hPa</td></tr>
        <tr><td>Humidity</td><td><span id="humidity">%HUMIDITY%</span>%</td></tr>
        <tr><td>Point de rosée</td><td><span id="point_de_rosée">%POINTDEROSEE%</span></td></tr>
        </table>

    
  
  
</body>

<script>



setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 2000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperatureF").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperatureF", true);
  xhttp.send();
}, 2000 ) ;



setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 2000 ) ;





</script>

</html>

)rawliteral";

//End Declarations

//function declaration**********************************************************************************


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
   double Tr = (pow((dht.readTemperature()/100),0.125))*(112+(0.9*dht.readTemperature()))+(0.1*dht.readTemperature())-112;
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
  }
}

   
String processor(const String& var){
  //Serial.println(var);
      if (var == "TEMPERATURE"){
         return readDHTTemperature();
      }
      else if (var == "HUMIDITY"){
         return readDHTHumidity();
      }
      else if (var == "TEMPERATUREF"){
         return readDHTTemperatureFahrenheit();
      }
      else if (var == "WHATER_LAVEL"){
         return readwatersenser();
      }
      else if (var == "PRESSURE"){
         return readPRESSURE();
      }
      else if (var == "POINTDEROSEE"){
         return readpointderosee();
      }
  return String();
}


void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}
//end funtion declaration********************************************************************************************************


void setup() {

  Serial.begin(115200);
  delay (10);

  // Connect to Wi-Fi network with SSID and password
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  server.onNotFound(notFound);
  
  Serial.println("Server started");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());



// Begin setup LCD
  lcd.begin ();
  lcd.clear (); 
// End setup LCD


// Begin setup DHT
  dht.begin();
// End setup DHT


// Begin setup BMP180
  bool success = bmp180.begin();
  if (success) {
    Serial.println("BMP180 init success");
  }
// End setup BMP180
/*
// Begin setup LDR
  pinMode (ldrPin, INPUT);
// END setup LDR
*/
server.begin();
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });


  /*server.on("/whater_lavel", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readwatersenser().c_str());
  });*/
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTTemperature().c_str());
  });
  server.on("/temperatureF", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTTemperatureFahrenheit().c_str());
  });/*
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readPRESSURE().c_str());
  });*/
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTHumidity().c_str());
  });/*
  server.on("/point_de_rosée", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readpointderosee().c_str());
  });*/
  
}


void loop() {

/*
// Begin loop LDR
  ldr_Val = analogRead (ldrPin);
  Serial.println (ldr_Val);
// End loop LDR
*/


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
