/*
   DIGF 6037 Creation & Computation
   Kate Hartman & Nick Puckett
   Experiment 3 - Lab 2
   Arduino to Processing - sending value for (3) analog values

   Circuit: 
   (3) analog sensors connected to pins A0, A1, A2   
*/


int sensor1val;
int sensor2val;
int sensor3val;

void setup() {
  //start serial connection
  Serial.begin(9600);
}

void loop() {
  // read the sensor value
  sensor1val = analogRead(0);
  // print out the sensor value
  Serial.print(sensor1val);
  // print a comma to separate the values
  Serial.print(",");

  // read the sensor value
  sensor2val = analogRead(1);
  // print out the sensor value
  Serial.print(sensor2val);
  // print a comma to separate the values
  Serial.print(",");

  // read the sensor value
  sensor3val = analogRead(2);
  // print out the sensor value and add a line break
  Serial.println(sensor3val);

  delay(100); // the delay is necessary for the serial communication


}
