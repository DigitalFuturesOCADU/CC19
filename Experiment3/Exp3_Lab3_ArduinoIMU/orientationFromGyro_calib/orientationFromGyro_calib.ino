/*
 * Creation & Computation
 * Determine Orientation from Gyroscope
 * Arduino Nano IOT33 - LSM6DS3
 */
#include <Arduino_LSM6DS3.h>
long lastRead;  //using this to measure time since last sensor reading

//these will hold the calculated angle value
float angleX;
float angleY;
float angleZ;

int mode = 0;  //using this for calibration
int calibTime = 4000;
float calibX;
float calibY;
float calibZ;

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
    float readInterval = ((millis()-lastRead)/1000.0);  
    IMU.readGyroscope(dsX, dsY, dsZ);  //read them and store the values into the variables
      if(mode==0)
      {
              
      calibX += dsX*readInterval;
      calibY += dsY*readInterval;
      calibZ += dsZ*readInterval;
          if(millis()>calibTime)
          {
            mode=1;
          }
      }
      
      if(mode==1)
      {
      angleX += (dsX*readInterval);
      angleY += (dsY*readInterval);
      angleZ += (dsZ*readInterval);
  
      ///print all the values
      Serial.print(dsX);
      Serial.print('\t');
      Serial.print(dsY);
      Serial.print('\t');
      Serial.print(dsZ);
      Serial.print('\t');
      Serial.print(readInterval);
      Serial.print('\t');
      Serial.print(angleX-calibX);
      Serial.print('\t');
      Serial.print(angleY-calibY);
      Serial.print('\t');
      Serial.print(angleZ-calibZ);
      Serial.print('\t');
      Serial.print(calibX);
      Serial.print('\t');
      Serial.print(calibY);
      Serial.print('\t');
      Serial.print(calibZ);
      Serial.println();
      }
    
    lastRead=millis(); //save the time to calculate the readInterval;
    }



}
