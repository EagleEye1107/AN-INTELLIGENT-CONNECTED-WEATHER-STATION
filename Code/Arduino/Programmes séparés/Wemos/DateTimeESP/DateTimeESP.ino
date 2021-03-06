#include <ESP8266WiFi.h>  // Built-in for ESP8266
#include "time.h" 

// Change to your WiFi credentials and select your time zone
const char* WIFI_SSID     = "D-Link";
const char* WIFI_PASSWORD = "30061969";
const char* Timezone = "GMT0BST,M3.5.0/01,M10.5.0/02";       // UK

//Example time zones
//const char* Timezone = "GMT0BST,M3.5.0/01,M10.5.0/02";     // UK
//const char* Timezone = "MET-2METDST,M3.5.0/01,M10.5.0/02"; // Most of Europe
//const char* Timezone = "CET-1CEST,M3.5.0,M10.5.0/3";       // Central Europe
//const char* Timezone = "EST-2METDST,M3.5.0/01,M10.5.0/02"; // Most of Europe
//const char* Timezone = "EST5EDT,M3.2.0,M11.1.0";           // EST USA  
//const char* Timezone = "CST6CDT,M3.2.0,M11.1.0";           // CST USA
//const char* Timezone = "MST7MDT,M4.1.0,M10.5.0";           // MST USA
//const char* Timezone = "NZST-12NZDT,M9.5.0,M4.1.0/3";      // Auckland
//const char* Timezone = "EET-2EEST,M3.5.5/0,M10.5.5/0";     // Asia
//const char* Timezone = "ACST-9:30ACDT,M10.1.0,M4.1.0/3":   // Australia

String Date_str, Time_str, Time_format;

void setup() {
  Serial.begin(9600);
  //dht.begin();

  
  //WiFi.disconnect();  //Prevent connecting to wifi based on previous configuration
  
  //WiFi.hostname(deviceName);      // DHCP Hostname (useful for finding device for static lease)
  //WiFi.config(staticIP, subnet, gateway, dns);
  //WiFi.mode(WIFI_STA);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println(WiFi.localIP());
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  setenv("TZ", Timezone, 1);
  Time_format = "M"; // or StartTime("I"); for Imperial 12:00 PM format and Date format MM-DD-CCYY e.g. 12:30PM 31-Mar-2019
}

void loop() {
  UpdateLocalTime(Time_format);
  Serial.println(Date_str);
  Serial.println(Time_str);
  Serial.println();
  delay(1000);
}

//#########################################################################################
void UpdateLocalTime(String Format){
  time_t now;
  time(&now);
  //See http://www.cplusplus.com/reference/ctime/strftime/
  char hour_output[30], day_output[30];
  if (Format == "M") {
    strftime(day_output, 30, "%a  %d-%m-%y", localtime(&now)); // Formats date as: Sat 24-Jun-17
    strftime(hour_output, 30, "%T", localtime(&now));    // Formats time as: 14:05:49
  }
  else {
    strftime(day_output, 30, "%a  %m-%d-%y", localtime(&now)); // Formats date as: Sat Jun-24-17
    strftime(hour_output, 30, "%r", localtime(&now));          // Formats time as: 2:05:49pm
  }
  Date_str = day_output;
  Time_str = hour_output;
}
//#########################################################################################
