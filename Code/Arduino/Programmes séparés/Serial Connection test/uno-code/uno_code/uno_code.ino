
char mystr[12] = "HelloUzerty"; //String data

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  Serial.write(mystr,12); //Write the serial data
  delay(1000);
  
}
