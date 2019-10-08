#include <Servo.h>
#include <animationTools.h>

////servo things
int servoRotation;
Servo s1;
int s1Pin = 10;
int distance1;
int threshhold1 = 1000;
float speedValue1 = 0.1;

////distance input
int sensorPin1 = 4;
int sensorVal1;

void setup() 
{
s1.attach(s1Pin);
  
  // put your setup code here, to run once:

}

void loop()
{
///remember how to read from distance sensor and do that...

distance1 = pulseIn(sensorPin1,HIGH);///read from the distance sensor

if(distance1<=threshhold1)  ///check if that value is smaller than the threshhold
{
  speedValue1 = 0.7         ///YES!!, change the speedValue be faster
}
else
{ 
  speedValue1 = 0.1;        ///NO!!, set it to be slower
}

  
  // put your main code here, to run repeatedly:


servoRotation = oscillate(60,100,0,speedValue1,millis());  //run the oscillate function to get the value
s1.write(servoRotation);  //apply that value to the servo
}
