#include <Servo.h>

Servo servo; 

int val; 

const int trigPin = 10;
const int echoPin = 9;
const int button = 7;
int buttonPressed = 0;
float distMax, distMin;
int buzzer = 6;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  servo.attach(12);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.034)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  if(digitalRead(button) == HIGH && buttonPressed == 0){
    distMin = distance;
    buttonPressed++;
    tone(buzzer, 1500);
    delay(500);
    noTone(buzzer);
    Serial.println("DISTMIN:");
    Serial.println(distMin);
    delay(500);
  }

  if(digitalRead(button) == HIGH && buttonPressed == 1 && distMin < distance){
    distMax = distance;
    buttonPressed++;
    tone(buzzer, 1500);
    delay(500);
    noTone(buzzer);
    Serial.println("DISTMAX:");   
    Serial.println(distMax);
    delay(500);
  }
  if(buttonPressed >=2){
  float val = map(distance, distMin, distMax, 0, 180); 
  val = constrain(val, 0, 180);
  servo.write(val);                 
  delay(50);
  }    
}