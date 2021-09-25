#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int sensorPin1 = A0;    // select the input pin for the potentiometer      // select the pin for the LED 
int sensorPin2 = A5;    // select the input pin for the potentiometer      // select the pin for the LED
int sensorValue = 0; 

#define in 14
#define out 19
#define relay 9

int count=0;

void IN()
{
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    Serial.println(count);
    delay(1000);
}

void OUT()
{
  count--;
    lcd.clear();
    lcd.print("Person In Room:");
    Serial.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    Serial.println(count);
    delay(1000);
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(10,2);
  lcd.print("Visitor Counter");
  Serial.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(relay, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
  Serial.print(count);
  Serial.print("h");
}

void loop()
{  
  
  if(digitalRead(in))
  IN();
  if(digitalRead(out))
  OUT();
  
  if(count<=0)
  {
    lcd.clear();
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light Is Off");
    delay(200);
  }
  
  else
    digitalWrite(relay, HIGH);
  
}
