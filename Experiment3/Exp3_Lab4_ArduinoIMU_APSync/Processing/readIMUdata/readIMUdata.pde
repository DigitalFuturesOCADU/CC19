/*
 * Creation & Computation 
 * read Orientation value from arduino using AP-Sync
 * Uses Arduino Nano33 IOT
 */
 
 
import apsync.*; // Include the AP sync library
import processing.serial.*; //Include Processing Serial
 
 String serialPort = "COM6";
 
 //variables that will hold value from arduino. These must be the same name as the ones used in the .sync command on the Arduino side
 //THESE MUST BE DECLARED AS PUBLIC
 public float ax;
 public float ay;
 public float az;
 
 
 PFont oText; //make a font object
 
AP_Sync readVals; //create apsync variable to read from   
 
 void setup()
 {
   size(1000,500); //create the window
   
   readVals = new AP_Sync(this, serialPort, 9600); //initialize the port and attach it to APsync. port speed must match the arduino side
   
   oText = createFont("Arial", 60);
   textFont(oText, 60);
   
 }
 
 void draw()
 {
   background(255);
   fill(0);
   textAlign(CENTER);
   text(ax+" : "+ay+" : "+az,width/2,height/2);
   
   
 }
