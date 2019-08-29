
/*
Creation & Computation - Kate Hartman
Video Example
*/


let playing = false;
let gloves;
let button;


function setup() 
{
  createCanvas(800,800);
  getAudioContext().resume();
  // specify multiple formats for different browsers
  gloves = createVideo(['GoGoGloves.mp4']);
  gloves.hide();
  button = createButton('play');
  button.mousePressed(toggleVid); // attach button listener
}

function draw()
{
background(100);
image(gloves, 400,400);

}


// plays or pauses the video depending on current state
function toggleVid() {
  if (playing) {
    gloves.pause();
    button.html('play');
  } else {
    gloves.loop();
    button.html('pause');
  }
  playing = !playing;
}