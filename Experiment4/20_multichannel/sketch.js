/*

Multi channel

This example shows methods for sending/receiving data on multiple channels
This technique is usuallly only needed when sending different types of messgaes

 */


// server variables for apps to communicate they must use THE SAME KEYS
//get these keys from your PubNub account
//within your group, you will use 1 of your accounts for the project

let dataServer;
let pubKey = 'insert your pub key';
let subKey = 'insert your sub key';

//name used to sort your messages. used like a radio station. can be called anything
let channel1 = "messages1";
let channel2 = "messages2";

let lastKeyPressed;

function setup() 
{
  
  createCanvas(windowWidth,windowHeight);
  background(255);
  
  

   // initialize pubnub
  dataServer = new PubNub(
  {
    publish_key   : pubKey,  //get these from the pubnub account online
    subscribe_key : subKey,  
    ssl: true  //enables a secure connection. This option has to be used if using the OCAD webspace
  });
  
  //attach callbacks to the pubnub object to handle messages and connections
 
  dataServer.subscribe({channels: [channel1,channel2]});   ///**note that both channels are listed here in the array 
 
  dataServer.addListener({ message: readIncoming});   ///even with multiple channels, they can still be handeld by a single callback



}

function draw() 
{


}


///uses built in mouseClicked function to send the data to the pubnub server
function mouseClicked() {
 

sendChannel1();

}

///uses built in keyPressed  function to to send the data to the pubnub server
function keyPressed() {
 lastKeyPressed = key;

  sendChannel2();
  
  }




function readIncoming(inMessage) 
{

/////we are using simple if statements to filter the incoming messages
  
 ////check to see which channel the message is on
  if(inMessage.channel == channel1)   ///channel 1
  {

    console.log(inMessage.channel+" says the mouse is at "+inMessage.message.mx+","+inMessage.message.my);
  }
 ////check to see which channel the message is on
  if(inMessage.channel == channel2)   ///channel 2
  {

   console.log(inMessage.channel+" says you pressed "+inMessage.message.messageText);
  }


}

function sendChannel1()
{
    dataServer.publish(
      {
        channel: channel1,
        message: 
        {
          mx: mouseX,
          my: mouseY      
        }
      });

}  

function sendChannel2()
{
    dataServer.publish(
      {
        channel: channel2,
        message: 
        {
          messageText: lastKeyPressed     
        }
      });

}  