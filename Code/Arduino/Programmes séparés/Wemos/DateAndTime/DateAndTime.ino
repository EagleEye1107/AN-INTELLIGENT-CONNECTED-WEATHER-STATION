#include <ESP8266WiFi.h>
#include <time.h>

const char* ssid = "D-Link";
const char* password = "30061969";

String dayStamp; 
String timeStamp;
  
int timezone = 1 * 3600;
int dst = 0;

void setup() {
  

  Serial.begin(115200);
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid,password);

  Serial.println();
  
  Serial.print("Connecting");

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }

  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  Serial.println("\nWaiting for Internet time");

  while(!time(nullptr)){
     Serial.print("*");
     delay(1000);
  }
  Serial.println("\nTime response....OK");   
}

void loop() {
  delay (1000);
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);

  dayStamp = String(p_tm->tm_mday)+"-"+String(p_tm->tm_mon + 1)+"-"+String(p_tm->tm_year + 1900);
  timeStamp = String(p_tm->tm_hour)+":"+String(p_tm->tm_min)+":"+String(p_tm->tm_sec);
  
  Serial.print(String(dayStamp));
  Serial.print(" ");
  Serial.println(String(timeStamp));
  
  delay(1000);

}
