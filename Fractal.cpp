#include <iostream>
#include <cstdint>
#include <memory>
#include <cmath>
#include "ZoomList.cpp"
#include "Bitmap.cpp"
#include "MandelBrot.cpp"

using namespace std;

int main()
{
      const int WIDTH = 300;
      const int HEIGHT = 200;

      dequinox::Bitmap bitmap(WIDTH, HEIGHT);

      //double min = 999999;
      //double max = -999999;

      unique_ptr<int[]> histogram(new int[dequinox::Mandelbrot::MAX_ITERATIONS + 1]{});
      unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{});

      for (int y = 0; y < HEIGHT; y++)
      {
            for (int x = 0; x < WIDTH; x++)
            {
                  double xFractal = (2.0 * x / (HEIGHT - 1.0)) - 2.0;
                  double yFractal = (2.0 * y / (HEIGHT - 1.0)) - 1.0;

                  int iterations = dequinox::Mandelbrot::getIterations(xFractal, yFractal);

                  fractal[y * WIDTH + x] = iterations;

                  if (iterations != dequinox::Mandelbrot::MAX_ITERATIONS)
                  {
                        histogram[iterations]++;
                  }

                  /*if (iterations == dequinox::Mandelbrot::MAX_ITERATIONS) continue;
                  if (iterations % 16 == 0) bitmap.setPixel(x,y, 66, 39, 15);
                  if (iterations % 16 == 1) bitmap.setPixel(x,y, 25, 7, 26);
                  if (iterations % 16 == 2) bitmap.setPixel(x,y, 9, 1, 47);
                  if (iterations % 16 == 3) bitmap.setPixel(x,y, 4, 4, 73);
                  if (iterations % 16 == 4) bitmap.setPixel(x,y, 0, 7, 100);
                  if (iterations % 16 == 5) bitmap.setPixel(x,y, 12, 44, 138);
                  if (iterations % 16 == 6) bitmap.setPixel(x,y, 24, 82, 177);
                  if (iterations % 16 == 7) bitmap.setPixel(x,y, 57, 125, 209);
                  if (iterations % 16 == 8) bitmap.setPixel(x,y, 134, 181, 229);
                  if (iterations % 16 == 9) bitmap.setPixel(x,y, 211, 236, 248);
                  if (iterations % 16 == 10) bitmap.setPixel(x,y, 241, 233, 191);
                  if (iterations % 16 == 11) bitmap.setPixel(x,y, 248, 201, 95);
                  if (iterations % 16 == 12) bitmap.setPixel(x,y, 255, 170, 0);
                  if (iterations % 16 == 13) bitmap.setPixel(x,y, 204, 128, 0);
                  if (iterations % 16 == 14) bitmap.setPixel(x,y, 153, 87, 0);
                  if (iterations % 16 == 15) bitmap.setPixel(x,y, 106, 52, 3);*/


                  //if (color < min) min = color;
                  //if (color > max) max = color;

            }
      }

      for (int i = 1; i < dequinox::Mandelbrot::MAX_ITERATIONS; i++)
      {
            histogram[i] += histogram[i - 1];
      }
      int total = histogram[dequinox::Mandelbrot::MAX_ITERATIONS - 1];

      for (int y = 0; y < HEIGHT; y++)
      {
            for (int x = 0; x < WIDTH; x++)
            {
                  uint8_t red = 0;
                  uint8_t green = 0;
                  uint8_t blue = 0;

                  int iterations = fractal[y * WIDTH + x];

                  if (iterations != dequinox::Mandelbrot::MAX_ITERATIONS)
                  {
                        double hue = (double)histogram[iterations] / total;
                        green = pow(255, hue);
                  }
                  bitmap.setPixel(x, y, red, green, blue);
            }
      }

      bitmap.write("test.bmp");


      cout << "Finished" << endl;
      return 0;
}
