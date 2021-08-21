#include <Servo.h> // Servo library 

// Horizontal servo
Servo horizontal; 
int servoh = 90;   // stand horizontal servo
int servohLimitHigh = 180;
int servohLimitLow = 65;

// Vertical servo
Servo vertical;    
int servov = 90;   // stand vertical servo
int servovLimitHigh = 120;
int servovLimitLow = 15;


// LDR pin connections
int ldrtl = 0; //LDR top left - BOTTOM LEFT
int ldrdl = 1; //LDR down left - TOP LEFT
int ldrdr = 2; //ldr down rigt - TOP RIGHT
int ldrtr = 3; //LDR top rigt - BOTTOM RIGHT 


void setup()
{
  Serial.begin(9600);
// servo connections
// servoName.attacht(servoPin);
  horizontal.attach(9); 
  vertical.attach(10);
// servoName.write(degreeValue);
  horizontal.write(180);
  vertical.write(45);
  delay(3000);
}

void loop() 
{
  int tl = analogRead(ldrtl); // top left
  int tr = analogRead(ldrtr); // top right
  int dl = analogRead(ldrdl); // down left
  int dr = analogRead(ldrdr); // down rigt
  
  int dtime = 2;
  int tol = 50; // Tolerance
  
  int avt = (tl + tr) / 2; // average value top
  int avd = (dl + dr) / 2; // average value down
  int avl = (tl + dl) / 2; // average value left
  int avr = (tr + dr) / 2; // average value right

  int dvert = avt - avd; // the difference of up and down (vertical)
  int dhoriz = avl - avr;// the difference of left and rigt (horizontal)
  
  
  Serial.print(avt);
  Serial.print(" ");
  Serial.print(avd);
  Serial.print(" ");
  Serial.print(avl);
  Serial.print(" ");
  Serial.print(avr);
  Serial.print("   ");
  Serial.print(dtime);
  Serial.print("   ");
  Serial.print(tol);
  Serial.println(" ");
  
// check if the diffirence is in the tolerance else change vertical angle    
  if (-1*tol > dvert || dvert > tol) 
  {
    if (avt > avd)
    {
      servov = ++servov;
      if (servov > servovLimitHigh) 
      { 
        servov = servovLimitHigh;
      }
    }
    
    else if (avt < avd)
    {
      servov= --servov;
      if (servov < servovLimitLow)
      {
        servov = servovLimitLow;
      }
    }
  vertical.write(servov);
  }
//

// check if the diffirence is in the tolerance else change horizontal angle  
  if (-1*tol > dhoriz || dhoriz > tol) 
  {
  if (avl > avr)
  {
    servoh = --servoh;
    if (servoh < servohLimitLow)
    {
    servoh = servohLimitLow;
    }
  }
  else if (avl < avr)
  {
    servoh = ++servoh;
     if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
  }
  else if (avl = avr)
  {
    // nothing
  }
  horizontal.write(servoh);
  }
//   
   delay(dtime);
}
