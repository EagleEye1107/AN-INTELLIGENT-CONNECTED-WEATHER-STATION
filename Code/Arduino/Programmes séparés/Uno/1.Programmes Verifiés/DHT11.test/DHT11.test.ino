
   #include <DHT.h>
 
   DHT dht(8,DHT11);
 
void setup() {
  Serial.begin(9600);
  dht.begin();
}
 
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float tf = dht.readTemperature(true);
 
    Serial.print("{\"humidity\": ");
    Serial.print(h);
    Serial.print(", \"temp\": ");
    Serial.print(t);
    Serial.print(", \"tempF\": ");
    Serial.print(tf);
    Serial.print("}\n");

    //point de rosee
    double val = (pow((h/100),0.125))*(112+(0.9*t))+(0.1*t)-112;
    Serial.println (String(val));
 
    delay(2000);
}
