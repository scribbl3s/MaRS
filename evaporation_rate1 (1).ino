#include<Adafruit_LiquidCrystal.h>

float oldmoisture=0;
float moisture = 0;
float temperature=0;
int CRO=3;
float evaporationrate=0;
Adafruit_LiquidCrystal lcd_1(0);
 

void setup()
{
  pinMode(A1,INPUT); //temp sensor to arduino
  pinMode(A0,INPUT); //moisture sensor to arduino
  Serial.begin(9600);
  pinMode(CRO,OUTPUT);
  lcd_1.begin(16,2);
  lcd_1.print("temp,evap_rate");
}

void loop()
{
   lcd_1.print("                ");
   lcd_1.setCursor(0,1);

  oldmoisture=moisture;
  moisture=((analogRead(A0))/87.60)*100;
  temperature=analogRead(A1);
  temperature=-40.0+((temperature-20)/338.0)*165.0;
  evaporationrate=-((moisture-oldmoisture)/10.0);
  lcd_1.print(temperature);
  lcd_1.print(",");
  lcd_1.print(evaporationrate);
  delay(1000);
}
