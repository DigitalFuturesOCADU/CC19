/*
 * Creation & Computation - Digital Futures, OCAD University
 * Kate Hartman / Nick Puckett
 * 
 * Fade between 2 colors
 * adapted from the LED fading arduino example
 * 
 */


let fadeRate = 10;        //the time between updates in milliseconds
let fadeIncrement = 0.05;    // how much to change the brightness each cycle 


let color1;
let color2;
let xFadeVal = 0;

let lastTimeYouChanged = 0;  //this stores the time of the last change


function setup() {
               

  createCanvas(windowWidth, windowHeight);
  color1 = color(255,0,250);
  color2 = color(200,250,30);
}

function draw() 
{

background(lerpColor(color2,color1,xFadeVal));

fill(lerpColor(color1,color2,xFadeVal));
noStroke();
ellipse(width/2,height/2,height/3,height/3);

if(millis()-lastTimeYouChanged>=fadeRate) //this very simple statement is the timer,
{                                          //it subtracts the value of the moment in time the last blink happened, and sees if that number is larger than your set blinking value

xFadeVal += fadeIncrement;

  if (xFadeVal <= 0 || xFadeVal >= 1) {
    fadeIncrement = -fadeIncrement;
  }

lastTimeYouChanged = millis();            //save the value in time that this switch occured, so we can use it again.
   
}



}


function windowResized() 
{
  resizeCanvas(windowWidth, windowHeight);
}


