const int cappluiepin = 7; // pin connecté à la sortie digital du capteur

void setup()
{
  Serial.begin(9600);
  pinMode(cappluiepin, INPUT);
}

void loop()
{
  if(digitalRead(cappluiepin) == LOW)
{
Serial.println("pluie"); // Allumer la LED
delay(10); // Temps de traitement
}
else
{
Serial.println("pas de pluie"); // Eteindre la LED
delay(10); // Temps de traitement
}
delay(1000);
}
