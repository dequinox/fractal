#include <iostream>
#include <cstdint>
#include "Bitmap.cpp"
#include "MandelBrot.cpp"

using namespace std;

int main()
{
      const int WIDTH = 1000;
      const int HEIGHT = 600;

      dequinox::Bitmap bitmap(WIDTH, HEIGHT);

      bitmap.setPixel(WIDTH/2, HEIGHT / 2, 255,255,255);

      double min = 999999;
      double max = -999999;

      for (int y = 0; y < HEIGHT; y++)
      {
            for (int x = 0; x < WIDTH; x++)
            {
                  double xFractal = (2.0 * x / (HEIGHT - 1.0)) - 2.0;
                  double yFractal = (2.0 * y / (HEIGHT - 1.0)) - 1.0;

                  int iterations = dequinox::Mandelbrot::getIterations(xFractal, yFractal);
                  uint8_t color = (uint8_t)(iterations * 256.0 / dequinox::Mandelbrot::MAX_ITERATIONS);

                  color = color * color * color;

                  bitmap.setPixel(x,y, 0, color, 0);
                  if (color < min) min = color;
                  if (color > max) max = color;

            }
      }

      cout << min << "," << max << endl;

      bitmap.write("test.bmp");

      cout << "Finished" << endl;
      return 0;
}
