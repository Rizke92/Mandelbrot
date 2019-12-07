/*
  Mandelbrot Challenge
  Eric Rizk
*/

#include <iostream>
#include "Complex.h"  
extern "C" {
#include "gfx.h"
}
//Set Size of Window
int height = 1000;
int width = 1000;
// Set the Range
double max_Range = 2.5;  
double min_Range = -2.5;
// Max Number of Iterations
int iterations = 200;
// If reaching infinit target
int target = 10; 
//center the mandelbrot
double moveX = .3;
double moveY = .6;


// Create new values for each coordinate
double map(double coordinate, double dimension, double min, double max)
{
	double value;
	value = coordinate * (max - min) / dimension + min;
	return value;
}


// Draw the Color of Point at Coordinates(x,y) 
void draw_Pixel(int var, int x, int y)
{
	double r, g, b;
	r =  (var / 1 * var) % 255;
	g = (var * 12) % 255;
	b = (var / var) % 255;
	gfx_color(r, g, b);
	gfx_point(x, y);
}

// Algorithm for Design
int mandelbrot(int xCord, int yCord)
{
	int brot = 0;
	double x = map(xCord, width, min_Range, max_Range) - moveX; // -.3
	double y = map(yCord, height, min_Range, max_Range) + moveY; // + .6
	Complex z(x, y);
	Complex c = z;
	while(brot < iterations)
	{
		z = z * z + c;
		if(absolute(z.real() + z.imag()) > target)
			break;
		brot++;
	}
	draw_Pixel(brot, xCord, yCord);
}



int main()
{
	gfx_open(1000, 1000, "Mandelbrot");
	std::cout << "\n";
	std::cout << "Press 'x'to Quit\n";
	std::cout << "Press 'z' to start zoom\n";
	
	for(int xCord = 0; xCord < width; xCord++)
	{
		for(int yCord = 0; yCord < height; yCord++)
		{
			mandelbrot(xCord, yCord);	
		}
	}
	
	while(true)
	{
		int button = gfx_wait();
		
		if(button == 'x') // x to quit
			break;
		if(button == 'z') // z to ZOOM
		{
			int count = 0;
			while(count != 9)
			{                  
				max_Range -= .22;
				min_Range += .22;
				width += 200;
				height += 200;
				// the zoom will push mandelbrot to bottom right
				//shift the mandelbrot
				moveX -= .02;// + to go right, - to got left
				moveY -= .09; // + up, - dwn
	
				for(int xCord = 0; xCord < width; xCord++)
				{
					for(int yCord = 0; yCord < height; yCord++)
					{
						mandelbrot(xCord, yCord);
					}
				}
				count++;
			}
			gfx_wait();
			if(button == 'x') // press x twice to quit
				break;
		}
	}
	std::cout << "\n";
	
	return 0;
}

