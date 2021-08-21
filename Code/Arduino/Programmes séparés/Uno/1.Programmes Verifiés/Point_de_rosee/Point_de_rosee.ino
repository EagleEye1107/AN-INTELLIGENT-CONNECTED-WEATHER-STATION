#include <DHTesp.h>
DHTesp dht;


void setup() {
  Serial.begin(115200);
  dht.setup(D8, DHTesp::DHT11);
}

void loop() {
  Serial.print("{\"humidity\": ");
  Serial.print(dht.getHumidity());
  Serial.print(", \"temp\": ");
  Serial.print(dht.getTemperature());
  Serial.print("}\n");
  double val = (pow((dht.getHumidity()/100),0.125))*(112+(0.9*dht.getTemperature()))+(0.1*dht.getTemperature())-112;
  Serial.println (String(val));
  delay (2000);
}
