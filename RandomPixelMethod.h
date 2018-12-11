#include "AreaAverageMethod.h"

#ifndef RANDOM_PIXEL_METHOD_H
#define RANDOM_PIXEL_METHOD_H

class RandomPixelMethod: public AreaAverageMethod{
public:
	RandomPixelMethod();
	RandomPixelMethod(unsigned char colorRadius);
	
private:
	unsigned char findColorAverageOf(ColorAverageArea* currentArea, unsigned char*** colorArray, uint color);
	unsigned char findRandomNearbyValue(ColorAverageArea* currentArea, unsigned char*** colorArray, uint color);
};

#endif