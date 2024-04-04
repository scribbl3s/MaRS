//displays wind direction and wind pressure

#include<Adafruit_LiquidCrystal.h>
#include<math.h>
float potential=A0;
int fsrpin=A1;
float angle=0;
//int force=0;
float windload=0;
float fsrreading=0;
int seconds=0;
Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  Serial.begin(9600);
  lcd_1.begin(16,2);
  lcd_1.print("angle , load");


}
void loop()
{
  lcd_1.setCursor(0,1);
  
  //for wind direction
  int potential = analogRead(A0);
  angle=45+(potential/1023.0)*270;
  lcd_1.print(angle);
  lcd_1.print(" , ");

  //for wind load on the sensor
  fsrreading = analogRead(fsrpin);
  windload=(fsrreading/466)*10;
  lcd_1.print(windload);
   

  delay(1000);
}

  
  