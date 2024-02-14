#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>



Adafruit_LiquidCrystal lcd(0);



int servoPin = 7;
int servoPos1 = 165;
int servoPos2 = 10;
int trigPin=6;
int encoPin=5;
Servo Myservo;
Servo Myservo2;
int Trigpin = 12;
int EncoPin = 11;
int distance;
int Leadred = 10;
int yellow=4;
int buzzerPin = 9;
int sensorPin = A0; 
int threshold = 500; 
int servoPin2 = 3;
int servoPos3 = 165;
int servoPos4 = 10;
long duration,duration1;
int distanceCm, percentage;
void setup()
{
  pinMode(Trigpin, OUTPUT);
  pinMode(EncoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(encoPin, INPUT);
  pinMode(Leadred, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Myservo.attach(servoPin);
  Serial.begin(9600);
  Myservo2.attach(servoPin2);
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  lcd.begin(16,2);
  
  
}

void loop(){
   lcd.setCursor(0,0);
  lcd.setBacklight(1); 
  delay(500);
  

  digitalWrite(Trigpin, LOW);
  delayMicroseconds(10);
  digitalWrite(Trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);
  duration1 = pulseIn(EncoPin, HIGH);
  distance= (duration1*0.034/2);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(encoPin, HIGH);
  int sensorValue = analogRead(sensorPin); 
  distanceCm= (duration*0.034/2);
  percentage= (((-10*distanceCm)+100)/9)+100 ;
 
   
  
  if(sensorValue < threshold){
    
  if(distance<=42) {
  lcd.print("Sensor value: ");
  lcd.print(sensorValue    );
    delay(2000);
    Myservo.write(servoPos1);
    digitalWrite(Leadred, HIGH);
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("The waste is Dry");
    delay(2000);
    lcd.setBacklight(1);
   
  
  }
  }
  
  
  delay(1000);
  
  if(distance>42.0) {
    Myservo.write(servoPos2);
     Myservo2.write(servoPos4);
    digitalWrite(Leadred, LOW);
    digitalWrite(buzzerPin, LOW); 
   lcd.clear();
    
   
    
  }
  if (sensorValue > threshold){
  if(distance<=42.0){
     lcd.print("Sensor value: ");
  lcd.print(sensorValue  );
     delay(2000);
     Myservo2.write(servoPos3);
    digitalWrite(yellow, HIGH);
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("The waste is Wet");
    lcd.setBacklight(1);
    delay(2000);
 
  }
  delay(1000);
    if(distance>42){
     
      digitalWrite(yellow, LOW);
      digitalWrite(buzzerPin, LOW);
      lcd.clear();
      
    }}
   lcd.setCursor(0,0);
  if(distanceCm>=100){
    lcd.print("The bin is empty   ");}
  else if (distanceCm <= 10.0){
  lcd.print("Overload   ");
  delay(1000);
  Serial.println("AT+CMGS=\"9353235773\""); 
  Serial.println("The bin is full");
  delay(1000);
  }else{
  lcd.print("Bin level: ");
  lcd.print(percentage);
  lcd.print("%   ");
  delay(0);
  lcd.setBacklight(1);;}
  delay(0);
  
  
}

 
  
 

  

