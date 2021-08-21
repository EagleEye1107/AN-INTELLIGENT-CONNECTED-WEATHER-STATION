char mystr[63];
//Initialized variable to store recieved data
//char *X[2] ;
//int i = 0;
//char *token;
void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  char *X[5];
  int i = 0;
  Serial.readBytes(mystr,63); //Read the serial data and store in var
  Serial.println(mystr); //Print data on Serial Monitor
  delay(1000);

  char *token = strtok(mystr , "U");
 
  while( token != NULL ) {
   //Serial.println("while( token != NULL ) code in");
    X [i]= token;i++;
    token = strtok(NULL, "U");
  }
    Serial.println(String(X[0]));
    Serial.println(String(X[1]));
    Serial.println(String(X[2]));
    Serial.println(String(X[3]));
    Serial.println(String(X[4]));
    /*
    Serial.println(String(X[5]));
    Serial.println(String(X[6]));
    */
}
