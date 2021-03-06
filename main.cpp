#include <iostream>
#include "Zoom.h"
#include "FractalCreator.cpp"

using namespace std;

int main()
{

	// Provide width and height of the image
      dequinox::FractalCreator fractalCreator(800, 600);

	// Add range of colors
      fractalCreator.addRange(0.0, dequinox::RGB(0, 0, 255));
      fractalCreator.addRange(0.005, dequinox::RGB(255, 99, 71));
      fractalCreator.addRange(0.008, dequinox::RGB(255, 215, 0));
      fractalCreator.addRange(1.0, dequinox::RGB(255, 255, 255));

	// Zoom in
      fractalCreator.addZoom(dequinox::Zoom(295, 202, 0.1));
      fractalCreator.addZoom(dequinox::Zoom(312, 304, 0.1));

	// Print fractal into test.bmp file
      fractalCreator.run("test.bmp");

      cout << "Finished" << endl;
      return 0;
}
