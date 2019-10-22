/*
DIGF 6037 Creation & Computation
   Kate Hartman & Nick Puckett
   Experiment 3 - Lab 2
   Arduino to Processing - sending value for (3) analog values

 Based on based on this Lab on the ITP Physical Computing site: 
 https://itp.nyu.edu/physcomp/labs/labs-serial-communication/two-way-duplex-serial-communication-using-an-arduino/
 */

import processing.serial.*; // import the Processing serial library
Serial myPort;              // The serial port
int sensor1;
int sensor2;
int sensor3;
float mappedSensor1;
float mappedSensor2;
float mappedSensor3;

void setup() {
  size(800, 300);
  // List all the available serial ports in the console
  printArray(Serial.list());

  // Change the 0 to the appropriate number of the serial port
  // that your microcontroller is attached to.
  String portName = Serial.list()[6];
  myPort = new Serial(this, portName, 9600);
  // read incoming bytes to a buffer
  // until you get a linefeed (ASCII 10):
  myPort.bufferUntil('\n');
}


void draw() {
  background(255);

  if (sensor1 > 400) {
    fill(57, 255, 20);
  } else {
    fill(253, 78, 179);
  }

  ellipse(width/3, mappedSensor1, 100, 100);

  if (sensor2 > 400) {
    fill(57, 255, 20);
  } else {
    fill(253, 78, 179);
  }

  ellipse(width/2, mappedSensor2, 100, 100);

  if (sensor3 > 400) {
    fill(57, 255, 20);
  } else {
    fill(253, 78, 179);
  }

  ellipse((width/3)*2, mappedSensor3, 100, 100);
}


void serialEvent(Serial myPort) {
  // read the serial buffer:
  String myString = myPort.readStringUntil('\n');
  if (myString != null) {
    // println(myString);
    myString = trim(myString);

    // split the string at the commas
    // and convert the sections into integers:
    int sensors[] = int(split(myString, ','));
    for (int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
      print("Sensor " + sensorNum + ": " + sensors[sensorNum] + "\t");
    }
    // add a linefeed at the end:
    println();
    sensor1 = sensors[0];  
    sensor2 = sensors[1]; 
    sensor3 = sensors[2];
    mappedSensor1 = map(sensor1, 0, 1023, height, 0);
    mappedSensor2 = map(sensor1, 0, 1023, height, 0);
    mappedSensor3 = map(sensor1, 0, 1023, height, 0);
  }
}
