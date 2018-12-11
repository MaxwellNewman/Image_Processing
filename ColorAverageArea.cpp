#include "ColorAverageArea.h"

ColorAverageArea::ColorAverageArea(uint row, uint col, unsigned char radius){
	this->radius = radius;
	this->color = color;
	findLimits(row, col);
	srand(time(NULL));

	//std::cout << radius << std::endl;
}

void ColorAverageArea::setColor(uint color){
	this->color = color;
}

void ColorAverageArea::findLimits(uint row, uint col){
	int lowerRow = row-radius;
	int lowerCol = col-radius;
	int upperRow = row+radius;
	int upperCol = col+radius;


	minimumRow = std::max(0, lowerRow);
	minimumCol = std::max(0, lowerCol);
	maximumRow = std::min(IMAGE_SIZE, upperRow);
	maximumCol = std::min(IMAGE_SIZE, upperCol);
	totalArea = (maximumCol - minimumCol) * (maximumRow - minimumRow);
}

uint ColorAverageArea::computeColorSum(unsigned char*** colorArray){
	uint colorSum = 0;

	for(uint i = minimumRow; i<maximumRow; ++i){
		for(uint j = minimumCol; j<maximumCol; ++j){
			colorSum += colorArray[i][j][color];
		}
	}

	return colorSum;
}

unsigned char ColorAverageArea::findAverageColor(unsigned char*** colorArray){
	uint colorSum = computeColorSum(colorArray);

	return colorSum / totalArea;
}

unsigned char ColorAverageArea::findRandomNearbyColor(unsigned char*** colorArray){
	std::pair<uint, uint> randomCell = selectRandomCell();
	uint randomCellRow = randomCell.first;
	uint randomCellCol = randomCell.second;

	unsigned char randomCellValue = colorArray[randomCellRow][randomCellCol][color];
	return randomCellValue;
}

std::pair<uint,uint> ColorAverageArea::selectRandomCell(){
	uint randomRow = selectRandomRow();
	uint randomCol = selectRandomColumn();

	return std::make_pair(randomRow, randomCol);
}

uint ColorAverageArea::selectRandomRow(){
	uint rowRange = (maximumRow - minimumRow);
	uint randomRow = rand() % (rowRange) + minimumRow;

	return randomRow;
}

uint ColorAverageArea::selectRandomColumn(){
	uint columnRange = (maximumCol - minimumCol);
	uint randomColumn = rand() % (columnRange) + minimumCol;
	
	return randomColumn;
}