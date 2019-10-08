int sensorPin = 4;
int distanceValue;
int prevDistanceValue;
int distanceChange;
int velocity;
int noiseThreshhold = 50;
String moveDirection;

void setup() 
{
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

if(velocity>noiseThreshhold)
{
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
Serial.println(moveDirection);
}

prevDistanceValue = distanceValue;
}
