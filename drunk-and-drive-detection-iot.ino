#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11);
  
int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 400;//threshold value for drunk
int speed = 7;

void setup()
{
pinMode(redled, OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT);
pinMode(speed,OUTPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop()
{
  int analogValue = analogRead(sensor);//value read by gas sensor
  Serial.print(analogValue);
  if(analogValue>sensorThresh)//condition if drunk
  {
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
    //play the buzzer with a frquency=4000Hz for 10 seconds.
    tone(buzzer,4000,10000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALCOHOL DETECTED.");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SENDING ALERT");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("STOPPING CAR...  ");
    delay(1000);
    lcd.clear();
    digitalWrite(speed,LOW);
    delay(5000);
  }
  else//condition if safe
  {
    digitalWrite(greenled,HIGH);
    digitalWrite(redled,LOW);
    digitalWrite(speed,HIGH);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SAFE");
    delay(1000);
    lcd.clear();
    delay(1000);
  }  
     
}