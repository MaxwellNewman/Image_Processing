#include "RandomPixelMethod.h"

RandomPixelMethod::RandomPixelMethod():AreaAverageMethod(){

}

RandomPixelMethod::RandomPixelMethod(unsigned char colorRadius):AreaAverageMethod(colorRadius){
	//nothing
}

unsigned char RandomPixelMethod::findColorAverageOf(ColorAverageArea* currentArea, unsigned char*** colorArray, uint color){
	return findRandomNearbyValue(currentArea, colorArray, color);
}

unsigned char RandomPixelMethod::findRandomNearbyValue(ColorAverageArea* currentArea, unsigned char*** colorArray, uint color){
	std::cout << "getting random" << std::endl;
	
	currentArea->setColor(color);
	unsigned char randomNearbyValue = currentArea->findRandomNearbyColor(colorArray);

	return randomNearbyValue;
}