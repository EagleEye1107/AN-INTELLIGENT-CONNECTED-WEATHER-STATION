   const int wspin = A4;
   int wsvalue;
   const char* ws;

void setup() {
  Serial.begin(9600);
  pinMode(wspin,INPUT);

}

void loop() {
  wsvalue= analogRead(wspin);
  if (wsvalue<530){ 
    ws = "0mm";
  }
  else if (wsvalue>=530 && wsvalue<550){ 
    ws = "10mm";
  }
  else if (wsvalue>=550 && wsvalue<580){ 
    ws = "20mm";
    } 
  else if (wsvalue>=580 && wsvalue<610){ 
    ws = "30mm";
    }
  else if (wsvalue>=610){ 
    ws = "40mm"; 
  }
  if (isnan(wsvalue)) {
    Serial.println("Failed to read from Water sensor!");
  }
  else {
  Serial.println(ws); 
}
delay(1000);
}
