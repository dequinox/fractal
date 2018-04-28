#include <iostream>
#include "Zoom.h"
#include "FractalCreator.cpp"

using namespace std;

int main()
{

      int width = 800;
      int height = 600;

      dequinox::FractalCreator fractalCreator(width, height);

      fractalCreator.addRange(0.0, dequinox::RGB(0, 0, 0));
      fractalCreator.addRange(0.3, dequinox::RGB(255, 0, 0));
      fractalCreator.addRange(0.5, dequinox::RGB(255, 255, 0));
      fractalCreator.addRange(1.0, dequinox::RGB(255, 255, 255));

      fractalCreator.addZoom(dequinox::Zoom(295, 202, 0.1));
      fractalCreator.addZoom(dequinox::Zoom(312, 304, 0.1));

      fractalCreator.run("test.bmp");

      cout << "Finished" << endl;
      return 0;
}
