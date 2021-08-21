#include <SFE_BMP180.h>


//BMP180
SFE_BMP180 bmp180;


String readBMPPressure() {
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
          return String(P);
          Serial.println(" hPa");
          Serial.print("Temperature: ");
          Serial.print(T);
          Serial.println(" C");
        }
        else {
              Serial.println("Failed to read from BMP sensor!");
              Serial.println(String(P));
              return "--";
          }
      }
    }
  }
}


setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("pressure").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/pressure", true);
  xhttp.send();
}, 10000 ) ;


// Begin setup BMP180
  bool success = bmp180.begin();
  if (success) {
    Serial.println("BMP180 init success");
  }
// End setup BMP180



 
    server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBMPPressure().c_str());
  });
 
