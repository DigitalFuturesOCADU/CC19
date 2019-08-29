/*
 * Creation & Computation - Digital Futures, OCAD University
 * Kate Hartman / Nick Puckett
 * 
 * Make a Grid of shapes
 * User may specify how many in each direction and the margin around them
 * This method uses map() to space them evenly
 */



let totalX = 50;
let totalY = 20;
let margin = 20;
let circRad = 20;

function setup()
{
createCanvas(800,600);

}


function draw()
{
	background(100);

	for (let x = 1; x<=totalX; x++)
	{
		for (let y = 1; y<=totalY; y++)
		{
			let gridX = map(x,1,totalX,margin,(width-margin));
			let gridY = map(y,1,totalY,margin,(height-margin));


			fill(255,10,10,50);
			stroke(0,220,10);

			ellipse(gridX,gridY,circRad,circRad);

		}	


	}



}
