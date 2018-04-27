#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>

#pragma pack(push, 2)

namespace darius
{
      struct BitmapFileHeader
      {
            char header[2]{'B', 'M'};
            int32_t filesize;
            int32_t reserverd{0};
            int32_t dataOffset;
      };
}
#pragma pack(pop)



#endif // BITMAPFILEHEADER_H
