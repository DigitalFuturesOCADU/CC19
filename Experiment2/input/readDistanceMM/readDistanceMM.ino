/*
 * Creation & Computation - Digital Futures, OCAD University
 * Kate Hartman / Nick Puckett
 * 
 * Reads from a Maxbotix Distance sensor via pulse width
 * It returns the value in millimeters 
 * 
 * 
 */


int pinNumber = 2; //the pin the pulsewidth is read on
int distanceMM; //variable that holds the reading

void setup() 

{

pinMode(pinNumber,INPUT);  //since we are using a digital pin, we must set tell it that it will be an INPUT

Serial.begin(9600); //turn on the serial port so we can read from the console
}

void loop() 

{
distanceMM = pulseIn(pinNumber, HIGH);//read the value from the sensor

Serial.print("Distance to object in MM: ");//print the value to the console
Serial.println(distanceMM);

}
