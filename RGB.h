#ifndef RGB_G
#define RGB_H

namespace dequinox {
      struct RGB
      {
                  double r;
                  double g;
                  double b;
                  RGB(double r, double g, double b);
      };
      RGB operator-(const RGB &first, const RGB &second);
}

#endif // RGB_H
