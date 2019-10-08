#include <animationTools.h>
#include <Servo.h>

int servoPin = 10;
Servo wagServo1;
int servoAngle;
float servoSpeed = 0.1;

int sensorPin = 4;
int distanceValue;
int prevDistanceValue;
int distanceChange;
float velocity;
int noiseThreshhold = 50;
String moveDirection;

void setup() 
{
  wagServo1.attach(servoPin);
  // put your setup code here, to run once:
pinMode(sensorPin, INPUT);
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
distanceValue = pulseIn(sensorPin, HIGH);
distanceChange = prevDistanceValue-distanceValue;
velocity = abs(distanceChange);


//Serial.println(servoSpeed);
if(velocity>noiseThreshhold)
{
servoSpeed = map(velocity,0,1000.0,100,800);
servoSpeed = servoSpeed/1000;
  if(distanceChange<0)
  {
    moveDirection = "BACKWARDS!!!!";  
  }
  else
  {
    moveDirection = "FORWARD!!!!";
  }

  
Serial.print("distance: ");
Serial.print(distanceValue);
Serial.print("  : Change: ");
Serial.print(velocity);
Serial.print(" direction: ");
Serial.print(moveDirection);
Serial.print(" sSpeed : ");
Serial.println(servoSpeed);
}


servoAngle = oscillate(0,180,0,servoSpeed,millis());
wagServo1.write(servoAngle);
prevDistanceValue = distanceValue;
}
