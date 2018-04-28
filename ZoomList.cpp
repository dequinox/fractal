#include "ZoomList.h"

namespace dequinox
{
      ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height)
      {

      }

      void ZoomList::add(const Zoom &zoom)
      {
            zooms.push_back(zoom);
            m_xCenter += (zoom.x - m_width/2.0)*m_scale;
            m_yCenter += -(zoom.y - m_height/2.0)*m_scale;

            m_scale *= zoom.scale;
      }
      std::pair<double, double> ZoomList::doZoom(int x, int y)
      {
            double xFractal = (double)(x - m_width / 2.0) * m_scale + m_xCenter;
            double yFractal = (double)(y - m_height / 2.0) * m_scale + m_yCenter;

            return std::pair<double, double>(xFractal, yFractal);
      }
}
