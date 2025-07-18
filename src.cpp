#include <Servo.h>

#define GasPin A0
#define ButtonPin 8
#define LedPin 2
#define BuzzerPin 7
#define ServoPin 3

bool ButtonPressed, AlarmOn;
int GasValue;

Servo myservo;

void setup()
{
  Serial.begin(9600);
  
  pinMode(GasPin, INPUT);
  pinMode(ButtonPin, INPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  
  myservo.attach(ServoPin);
  myservo.write(0);
  AlarmOn = false;
}

void loop()
{	
  GasValue = analogRead(GasPin);
  ButtonPressed = digitalRead(ButtonPin);

  Serial.println(AlarmOn);
  
  if (ButtonPressed && AlarmOn) {
    AlarmOn = false;
  }
  
  if (GasValue > 50) {
    AlarmOn = true;
  }
  
  if (AlarmOn) {
  	digitalWrite(LedPin, HIGH);
    digitalWrite(BuzzerPin, HIGH);
    myservo.write(180);
  } else {
  	digitalWrite(LedPin, LOW);
    digitalWrite(BuzzerPin, LOW);
    myservo.write(0);
  }
}