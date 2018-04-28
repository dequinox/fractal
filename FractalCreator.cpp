#include "FractalCreator.h"
#include "MandelBrot.cpp"

namespace dequinox
{
      void FractalCreator::run(std::string name)
      {

            calculateIteration();
            calculateTotalIteration();
            drawFractal();
            writeBitmap(name);
      }
      FractalCreator::FractalCreator(int width, int height) : m_width(width), m_height(height),
            m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{}), m_fractal(new int[m_width * m_height]{}),
            m_bitmap(width, height), m_zoomList(width, height)
      {
            m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
      }

      void FractalCreator::drawFractal()
      {
            RGB startColor(0, 0, 0);
            RGB endColor(0, 255, 255);
            RGB colorDiff = endColor - startColor;

            for (int y = 0; y < m_height; y++)
            {
                  for (int x = 0; x < m_width; x++)
                  {
                        uint8_t red = 0;
                        uint8_t green = 0;
                        uint8_t blue = 0;

                        int iterations = m_fractal[y * m_width + x];

                        if (iterations != Mandelbrot::MAX_ITERATIONS)
                        {
                              double hue = (double)m_histogram[iterations] / m_total;
                              red = startColor.r + colorDiff.r*hue;
                              green = startColor.g + colorDiff.g*hue;
                              blue = startColor.b + colorDiff.b*hue;
                        }
                        m_bitmap.setPixel(x, y, red, green, blue);
                  }
            }
      }

      void FractalCreator::calculateTotalIteration()
      {
            for (int i = 1; i < Mandelbrot::MAX_ITERATIONS; i++)
            {
                  m_histogram[i] += m_histogram[i - 1];
            }
            m_total = m_histogram[Mandelbrot::MAX_ITERATIONS - 1];
      }

      void FractalCreator::calculateIteration()
      {
            for (int y = 0; y < m_height; y++)
            {
                  for (int x = 0; x < m_width; x++)
                  {
                        std::pair <double, double> coords = m_zoomList.doZoom(x, y);

                        int iterations = Mandelbrot::getIterations(coords.first, coords.second);

                        m_fractal[y * m_width + x] = iterations;

                        if (iterations != Mandelbrot::MAX_ITERATIONS)
                        {
                              m_histogram[iterations]++;
                        }

                        /*if (iterations == dequinox::Mandelbrot::MAX_ITERATIONS) continue;
                        if (iterations % 16 == 0) m_bitmap.setPixel(x,y, 66, 39, 15);
                        if (iterations % 16 == 1) m_bitmap.setPixel(x,y, 25, 7, 26);
                        if (iterations % 16 == 2) m_bitmap.setPixel(x,y, 9, 1, 47);
                        if (iterations % 16 == 3) m_bitmap.setPixel(x,y, 4, 4, 73);
                        if (iterations % 16 == 4) m_bitmap.setPixel(x,y, 0, 7, 100);
                        if (iterations % 16 == 5) m_bitmap.setPixel(x,y, 12, 44, 138);
                        if (iterations % 16 == 6) m_bitmap.setPixel(x,y, 24, 82, 177);
                        if (iterations % 16 == 7) m_bitmap.setPixel(x,y, 57, 125, 209);
                        if (iterations % 16 == 8) m_bitmap.setPixel(x,y, 134, 181, 229);
                        if (iterations % 16 == 9) m_bitmap.setPixel(x,y, 211, 236, 248);
                        if (iterations % 16 == 10) m_bitmap.setPixel(x,y, 241, 233, 191);
                        if (iterations % 16 == 11) m_bitmap.setPixel(x,y, 248, 201, 95);
                        if (iterations % 16 == 12) m_bitmap.setPixel(x,y, 255, 170, 0);
                        if (iterations % 16 == 13) m_bitmap.setPixel(x,y, 204, 128, 0);
                        if (iterations % 16 == 14) m_bitmap.setPixel(x,y, 153, 87, 0);
                        if (iterations % 16 == 15) m_bitmap.setPixel(x,y, 106, 52, 3);
                        */
                  }
            }

      }

      void FractalCreator::addRange(double rangeEnd, const RGB &rgb)
      {
            m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
            m_colors.push_back(rgb);
      }

      void FractalCreator::addZoom(const Zoom &zoom)
      {
            m_zoomList.add(zoom);
      }

      void FractalCreator::writeBitmap(std::string filename)
      {
            m_bitmap.write("test.bmp");
      }

      FractalCreator::~FractalCreator()
      {

      }
}
