/* Buzzer est un programme qui joue la gamme musicale */
 
#define buzzer D8                                                                     // affectation des broches
int frequence = 494;      // tableau de fréquence des notes

void setup()
{

}

void loop()
{
  for (int i = 0; i < 8; i++)
  {
  tone(buzzer, frequence, 500);                                                  // la note est jouée pendant 500 ms

  delay(1000);                                                                                    // attente de 500 ms entre chaque note
  }
}
