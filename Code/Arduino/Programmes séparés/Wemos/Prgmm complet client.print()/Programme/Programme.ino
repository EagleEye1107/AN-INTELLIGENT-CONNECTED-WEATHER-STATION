///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PS : La température est prise du DHT11 et non pas du BMP180 (moins de précision pour le DHT11)
// à la fin de la réalisation du projet switch temp form DHT11 to BMP180

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Begin Librairies
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHTesp.h>
#include <SFE_BMP180.h>
//End Librairies

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Begin Declarations

//Web-server

const char* ssid     = "D-Link";
const char* password = "30061969";
/*
const char* ssid     = "TP-LINK_4D8B97";
const char* password = "80803096";
*/
// Set web server port number to 80
WiFiServer server(80);
// Variable to store the HTTP request
String header;

//LCD
LiquidCrystal_I2C lcd (0x3F, 16, 2);

//DHT
DHTesp dht;

//Water Sensor
const int wspin = A0;
int wsvalue;
const char* ws;

//BMP180
SFE_BMP180 bmp180;


double ptr;
//End Declarations

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    Serial.println("Not connected");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  server.begin();
  Serial.println("Server started");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

// Begin setup LCD
  lcd.begin ();
  lcd.clear (); 
// End setup LCD


// Begin setup DHT
  Serial.begin(115200);
  dht.setup(D8, DHTesp::DHT11);
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
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

// Begin loop DHT
  Serial.print("{\"humidity\": ");
  Serial.print(dht.getHumidity());
  Serial.print(", \"temp\": ");
  Serial.print(dht.getTemperature());
  Serial.print("}\n");
// End loop DHT


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




// Begin Point de rosée
   double Tr = (pow((dht.getHumidity()/100),0.125))*(112+(0.9*dht.getTemperature()))+(0.1*dht.getTemperature())-112;
   Serial.println ("Point de rosee : ");
   Serial.println (String(Tr));
// End Point de rosée


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
    lcd.print (""+ String(dht.getTemperature()) +" C- "+ String((((dht.getTemperature())*(9/5))+32)) +" F");
    // lcd.print (""+ String(T) +" C- "+ String((T*(9/5))+32)) +" F"); //BMP180
    delay (2000);
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print ("HUMIDITY : ");
    lcd.setCursor (4,1);
    lcd.print (" " + String(dht.getHumidity()) +"%");
    delay (2000);
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print ("PRESSURE : ");
    lcd.setCursor (4,1);
    lcd.print (" " + String(P) +"hPa");  
    delay (2000);
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print ("WATER LEVEL : ");
    lcd.setCursor (2,1);
    lcd.print (" "+ String(ws) +" ");  
    delay (2000);
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print ("Point de rosee : ");
    lcd.setCursor (4,1);
    lcd.print (" "+ String(Tr) +" ");  
    delay (2000);
// End loop LCD


//Begin partie Web Server
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();


//html display-----------------------------------------------------------------------------------------

client.println("<!DOCTYPE html>");
client.println("<html lang=""en"">");
client.println("<HEAD><meta http-equiv=\"refresh\" content=\"5\"></HEAD>");

//css declaration***********************

client.println("<style>");
client.println(" body { text-align: center; font-family: \"Trebuchet MS\", Arial;}");
client.println(" table { border-collapse: collapse; width:35%; margin-left:auto; margin-right:auto; }");
client.println(" th { padding: 14px; background-color: #02ffff; color: rgb(0, 0, 0); }");
client.println(" tr { border: 1px solid rgb(0, 0, 0); padding: 10px; }");
client.println("  tr:hover { background-color: #000; color: aliceblue;}");
client.println(" td { border: none; padding: 12px; }</style>");

// html body and title******************

client.println("<title>HTML page of web server</title></head>");
client.println("<body><h1>arduino weather station wemos D1 </h1>");
client.println("<table><tr><th>MEASUREMENT</th><th>VALUE</th></tr>");
client.println("<tr><td>Water Level</td><td>"+ String(ws) +"</td></tr>");
client.println("<tr><td>Temp. Celsius</td><td>"+ String(dht.getTemperature()) +" C</td></tr>");
client.println("<tr><td>Temp. Fahrenheit</td><td>"+ String((((dht.getTemperature())*(9/5))+32)) +" F</td></tr>");
client.println("<tr><td>Pressure</td><td>"+ String(P) +"hPa</td></tr>");
client.println("<tr><td>Humidity</td><td>"+ String(dht.getHumidity()) +"%</td></tr>");
client.println("<tr><td>Point de rosée</td><td>"+ String(Tr) +"</td></tr></table>");
client.println("</body></html>");


// The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
//End partie Web Server
}
