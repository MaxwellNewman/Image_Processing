#include "AreaAverageMethod.h"

#ifndef RANDOM_PIXEL_METHOD_H
#define RANDOM_PIXEL_METHOD_H

class RandomPixelMethod: public AreaAverageMethod{
public:
	RandomPixelMethod();
	RandomPixelMethod(unsigned char colorRadius);
	void makeBlurry();
	void swapSingleCell(uint row, uint col);
	
private:
	unsigned char findRandomNearbyValue(ColorAverageArea* currentArea, unsigned char*** colorArray, uint color);
	void swapOneCellWithOneOther(uint row, uint col);
};

#endif