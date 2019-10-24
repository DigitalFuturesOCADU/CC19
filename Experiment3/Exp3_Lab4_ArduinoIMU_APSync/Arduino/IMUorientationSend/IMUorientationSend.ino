/*
 * Creation & Computation 
 * Send orientation & accel data to Processing using AP-Sync
 * Uses Arduino Nano33 IOT
 */

#include <Arduino_LSM6DS3.h>
#include <AP_Sync.h>

AP_Sync sendData(Serial); // Create an Object named sendData of type APsync


long lastRead;  //using this to measure time since last sensor reading

//these will hold the calculated angle value
float angleX;
float angleY;
float angleZ;

void setup() 
{
  Serial.begin(9600);

  if(!IMU.begin())  //initalize the sensor print an error if it doesn't turn on
  {
  Serial.println("IMU isn't working....");   
  }

}

void loop() 
{
float dsX, dsY, dsZ;  //temporary variables for holding the degrees/second values

    if (IMU.gyroscopeAvailable()) //check if values are available
    {
    IMU.readGyroscope(dsX, dsY, dsZ);  //read them and store the values into the variables
    
    float readInterval = ((millis()-lastRead)/1000.0);
    angleX += dsX*readInterval;
    angleY += dsY*readInterval;
    angleZ += dsZ*readInterval;

    ///sendValue to Processing
    sendData.sync("ax",angleX);
    sendData.sync("ay",angleY);
    sendData.sync("az",angleZ);

        
    
    lastRead=millis(); //save the time to calculate the readInterval;
    }



}
