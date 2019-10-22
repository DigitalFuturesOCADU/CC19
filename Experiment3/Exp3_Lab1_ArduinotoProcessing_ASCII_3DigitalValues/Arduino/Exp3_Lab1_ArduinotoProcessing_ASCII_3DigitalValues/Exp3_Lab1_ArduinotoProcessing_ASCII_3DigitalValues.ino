/*
   DIGF 6037 Creation & Computation
   Kate Hartman & Nick Puckett
   Experiment 3 - Lab 1
   Arduino to Processing - sending value for (3) digital values

   Circuit: 
   switch connected to pin 2 and ground
   switch connected to pin 3 and ground
   switch connected to pin 4 and ground   
*/

int switch1val;
int switch2val;
int switch3val;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pins as inputs and enable the internal pull-up resistor
  //this helps to simpify the physical circuit
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop() {
  // read the switch value
  switch1val = digitalRead(2);
  // print out the switch value
  Serial.print(switch1val);
  // print a comma to separate the values
  Serial.print(",");

  // read the switch value
  switch2val = digitalRead(3);
  // print out the switch value
  Serial.print(switch2val);
  // print a comma to separate the values
  Serial.print(",");

  // read the switch value
  switch3val = digitalRead(4);
  // print out the switch value and add a line break
  Serial.println(switch3val);

  delay(100); // the delay is necessary for the serial communication

  // Turn on the built in LED any time any of the switches are activated
  if (switch1val == LOW || switch2val == LOW || switch3val == LOW) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}
