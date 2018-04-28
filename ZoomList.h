#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <vector>
#include <utility>
#include "Zoom.h"

namespace dequinox
{
      class ZoomList
      {
            private:
                  double m_xCenter;
                  double m_yCenter;
                  double m_scale{1.0};

                  int m_width{0};
                  int m_height{0};
                  std::vector<Zoom> zooms;
            public:
                  ZoomList(int width, int height);
                  void add(const Zoom &zoom);
                  std::pair<double, double> doZoom(int x, int y);
      };
}

#endif // ZOOMLIST_H
