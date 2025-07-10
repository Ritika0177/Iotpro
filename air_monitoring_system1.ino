#include <LiquidCrystal.h>

LiquidCrystal LCD(5, 6, 8, 9, 10, 11);

int RedLED=3;
int GreenLED=2;
int Sensor=A0;

float sensorvalue=0;
float voltage;
float Temperature;

int Max = 400;

void setup()
{ 
  pinMode(A1,INPUT);
  pinMode(Sensor,INPUT);
  pinMode(Sensor, INPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  Serial.begin(9600);
  LCD.begin(16, 2);
}

void loop()
{ 
  sensorvalue=analogRead(A1);
  voltage=sensorvalue*5.0/1024;
  Temperature=(voltage-0.5)*100;
  Serial.print("Sensor Value");
  Serial.println(sensorvalue);
  Serial.print("Temperature: ");
  Serial.print(Temperature);
  Serial.println(" degree Celcius");
  
  
   LCD.setCursor(0,0);
   LCD.print("Temperature: ");
   LCD.print(Temperature);
   delay(1000);
  
  
  int PPM = analogRead(Sensor);
  Serial.println(PPM);
  LCD.clear();
  LCD.setCursor(0 ,0);
  LCD.print("Air Qlty:");
  LCD.print(PPM);
  LCD.print(" PPM");
  if(PPM > Max) {
    digitalWrite(RedLED, HIGH);
    digitalWrite(GreenLED, LOW);
    LCD.setCursor(0, 1);
    LCD.print("ALERT!!!");
    delay(1000);
  }
  else {
    digitalWrite(RedLED, LOW);
    digitalWrite(GreenLED, HIGH);
    LCD.setCursor(0, 1);
    LCD.print("SAFE :)");
    delay(1000);
  }
  
  
  
}