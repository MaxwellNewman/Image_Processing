#include "BlurryMethod.h"
#include "ColorAverageArea.h"

#ifndef AREA_AVERAGE_METHOD_H
#define AREA_AVERAGE_METHOD_H

class AreaAverageMethod : public BlurryMethod {
public:
	AreaAverageMethod();
	AreaAverageMethod(unsigned char colorRadius);
	void makeBlurry();
	void setColorRadius(unsigned char colorRadius);
private:
	unsigned char colorRadius;
	unsigned char findColorAverageOf(ColorAverageArea* currentArea, unsigned char*** colorArray, uint color);
	void averageSingleCell(uint row, uint col);
};

#endif