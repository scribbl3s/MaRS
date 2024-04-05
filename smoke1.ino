//
int MQ2pin=A0;
int switch_pin=12;
int switch_value=0;
int motor_pin=2;
const int buzzer_pin=4;
float exhaust_threshold=100.00;
float alarm_threshold=250.00;
float relative_conc=0;

void setup()
{
  Serial.begin(9600);
  pinMode(motor_pin,OUTPUT);
  pinMode(buzzer_pin,OUTPUT);
  pinMode(switch_pin, INPUT); //initialize

  //delay(20000); // allow the MQ2 to warm up
}

void loop()
{
  digitalWrite(motor_pin,LOW);
  noTone(buzzer_pin);
  switch_value = digitalRead(switch_pin);

  if(switch_value==HIGH)
  {
  relative_conc = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.println("Sensor Value: ");
  Serial.println(relative_conc);

  if((relative_conc > exhaust_threshold)&&(relative_conc < alarm_threshold))
  {
    Serial.print("\nSmoke detected!");
    digitalWrite(motor_pin,HIGH); //exhaust fan spins

  }
  else if(relative_conc >= alarm_threshold)
  {
    Serial.println("\nToo much smoke detected!");
    tone(buzzer_pin,550); //alarm rings

  }
  else
  {
   Serial.println("air is good");
  }
            delay(2000);

  }
  else
  {
    delay(2000);
  }
}
