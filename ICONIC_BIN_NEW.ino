//Team ICONIC ( Smart Trash Bin Arduino Code)

#include<Servo.h>

#define trigPin2 10
#define echoPin2 11
Servo myservo;

int Limit = 27; //height limit of our garbage bin in cm (27cm)
const int trigPin = 3;
const int echoPin = 2;
long duration, percentage, range;
int led = 6; //LED connect to digital pin 6
int buzzer = 7;//Buzzer connect to digital pin 7

void setup() {
  //Get outputs
 Serial.begin(9600);
 pinMode(led, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzzer,OUTPUT);
 myservo.attach(9);//Servo motor connect to digital pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  percentage = (duration / 2) / 29.1 / Limit * 100;
  range = 100 - percentage;//The size of trash in the trash can as a percentage

if ((range >= 0) && (range <= 100))
  {
    if (range > 70)
      {
        Serial.print("F ");//Full
      }
    if ((range >= 30) && (range <= 70))
      {
        Serial.print("M ");//Mediation
      }
    if (range <= 30)
      {
        Serial.print("E ");//Empty
      }
    
     Serial.print(range);
     Serial.println();
     delay(500);
  }
  
else
 {
  Serial.print("F 100");
  Serial.println();
  delay(500);
 }
 long duration, distance; 
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  
 
if((distance<14)) 
{ 
digitalWrite(led, HIGH);//LED ON
}
 else if(distance>14)
 {
 digitalWrite(led, LOW); //LED OFF
 }
if((distance<=7)) 
{ 
digitalWrite(buzzer, HIGH); //BUZZER ON
}
 else if(distance>7)
 {
 digitalWrite(buzzer, LOW); //BUZZER OFF
}

{
  
 long duration, distance;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance < 30) { //if an object is detected at a distance of less than 30cm, the trash can will open automatically.

myservo.write(180);
  }
  else {
  myservo.write(0); 
  }
  delay(500);
}
}
