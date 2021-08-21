#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd (0x3F, 16, 2);
int abc = 123;


void setup() {
  lcd.begin ();
  lcd.clear ();
}

void loop() {
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print ("TEMP : ");
    lcd.setCursor (4,1);
    lcd.print (" "+ String(abc) + "C");
    delay (2000);

    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print ("HUMIDITY : ");
    lcd.setCursor (4,1);
    lcd.print (" " + String(abc + 1) +"%");
    delay (2000);

    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print ("PRESSURE : ");
    lcd.setCursor (4,1);
    lcd.print (" "+ String(abc + 2) + "hPa");  
    delay (2000);
}
