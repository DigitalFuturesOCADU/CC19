/*
 * Creation & Computation 
 * read Orientation value from arduino using AP-Sync
 * Uses Arduino Nano33 IOT
 */
 
 
import apsync.*; // Include the AP sync library
import processing.serial.*; //Include Processing Serial
import controlP5.*;
 
 String serialPort = "COM6";
 
 //variables that will hold value from arduino. These must be the same name as the ones used in the .sync command on the Arduino side
 //THESE MUST BE DECLARED AS PUBLIC
 public float ax;
 public float ay;
 public float az;
 
 
 PFont oText; //make a font object
 
AP_Sync readVals; //create apsync variable to read from   

ControlP5 controller; //create cp5 variable to attach interface items to

float cpX;
float cpY;
float cpZ;
 
 void setup()
 {
   size(1000,500); //create the window
   
   readVals = new AP_Sync(this, serialPort, 9600); //initialize the port and attach it to APsync. port speed must match the arduino side
   
   oText = createFont("Arial", 60);
   textFont(oText, 60);
   
   
   controller = new ControlP5(this);
   
   controller.addSlider("cpX")
             .setPosition(10,50)
             .setRange(-200.0,200.0)
             .setHeight(40)
             .setValue(0)
             .setColorLabel(0)
             .setDecimalPrecision(2)
             ;
   controller.addSlider("cpY")
             .setPosition(10,100)
             .setRange(-200.0,200.0)
             .setHeight(40)
             .setValue(0)
             .setColorLabel(0)
             .setDecimalPrecision(2)
             ;
   controller.addSlider("cpZ")
             .setPosition(10,150)
             .setRange(-1200.0,1200.0)
             .setHeight(40)
             .setValue(0)
             .setColorLabel(0)
             .setDecimalPrecision(2)
             ;
   
   
 }
 
 void draw()
 {
   background(255);
   fill(0);
   textAlign(CENTER);
   text((ax-cpX)+" : "+(ay-cpY)+" : "+(az-cpZ),width/2,height/2);
   
   
 }
