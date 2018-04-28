#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include "Zoom.h"
#include <iostream>
#include <assert.h>
#include <memory>
#include <vector>
#include "Bitmap.cpp"
#include "ZoomList.cpp"
#include "RGB.cpp"

namespace dequinox
{
      class FractalCreator
      {
            private:
                  int m_width;
                  int m_height;
                  std::unique_ptr<int[]> m_histogram;
                  std::unique_ptr<int[]> m_fractal;
                  Bitmap m_bitmap;
                  ZoomList m_zoomList;
                  int m_total{0};

                  std::vector<int> m_ranges;
                  std::vector<RGB> m_colors;
                  std::vector<int> m_rangeTotals;

                  bool m_GotFirstRange{false};

            private:

                  void calculateIteration();
                  void drawFractal();
                  void calculateTotalIteration();
                  void writeBitmap(std::string name);
                  void calculateRangeTotals();
                  int getRange(int iterations) const;

            public:
                  FractalCreator(int width, int height);
                  void addZoom(const Zoom &zoom);
                  void addRange(double rangeEnd, const RGB &rgb);
                  void run(std::string name);
                  virtual ~FractalCreator();
      };
}

#endif // FRACTALCREATOR_H
