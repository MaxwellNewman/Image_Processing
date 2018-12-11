#include <sys/types.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "stdlib.h"
#include <time.h>

#ifndef COLOR_AVERAGE_AREA_H
#define COLOR_AVERAGE_AREA_H

class ColorAverageArea{
public:
	ColorAverageArea(uint row, uint col, unsigned char radius);
	unsigned char findAverageColor(unsigned char*** colorArray);
	void setColor(uint color);
	unsigned char findRandomNearbyColor(unsigned char*** colorArray);
	std::pair<uint,uint> selectRandomCell();

private:
	uint minimumRow;
	uint minimumCol;
	uint maximumRow;
	uint maximumCol;
	uint totalArea;
	uint color;
	unsigned char radius;
	const int IMAGE_SIZE = 256;

	void findLimits(uint row, uint col);
	uint computeColorSum(unsigned char*** colorArray);
	uint selectRandomRow();
	uint selectRandomColumn();
};

#endif