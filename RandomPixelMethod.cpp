#include "RandomPixelMethod.h"

RandomPixelMethod::RandomPixelMethod():AreaAverageMethod(){

}

RandomPixelMethod::RandomPixelMethod(unsigned char colorRadius):AreaAverageMethod(colorRadius){
	//nothing
}

unsigned char RandomPixelMethod::findRandomNearbyValue(ColorAverageArea* currentArea, unsigned char*** colorArray, uint color){
	currentArea->setColor(color);
	unsigned char randomNearbyValue = currentArea->findRandomNearbyColor(colorArray);

	return randomNearbyValue;
}

void RandomPixelMethod::makeBlurry(){
	for(uint i=0; i<IMAGE_SIZE; ++i){
		for(uint j=0; j<IMAGE_SIZE; ++j){
			swapSingleCell(i, j);
			//swapOneCellWithOneOther(i,j);
		}
	}
}

void RandomPixelMethod::swapSingleCell(uint row, uint col){
	ColorAverageArea* currentArea = new ColorAverageArea(row, col, colorRadius);

	outputImage[row][col][RED] = findRandomNearbyValue(currentArea, inputImage, RED);
	outputImage[row][col][GREEN] = findRandomNearbyValue(currentArea, inputImage, GREEN);
	outputImage[row][col][BLUE] = findRandomNearbyValue(currentArea, inputImage, BLUE);
}

void RandomPixelMethod::swapOneCellWithOneOther(uint row, uint col){
	ColorAverageArea* currentArea = new ColorAverageArea(row, col, colorRadius);

	std::pair<uint, uint> randomCell = currentArea->selectRandomCell();
	uint randomRow = randomCell.first;
	uint randomCol = randomCell.second;

	outputImage[row][col][RED] = inputImage[randomRow][randomCol][RED];
	outputImage[row][col][GREEN] = inputImage[randomRow][randomCol][GREEN];
	outputImage[row][col][BLUE] = inputImage[randomRow][randomCol][BLUE];
}