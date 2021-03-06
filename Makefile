# Name: Maxwell Newman
# email: maxwellnewman100@gmail.com

CC = g++
CFLAGS = -g -Wall -std=c++11
SRCS =  bmplib.cpp BlurryMethod.cpp AreaAverageMethod.cpp ColorAverageArea.cpp RandomPixelMethod.cpp
TARGET = blurry

all: blurry

blurry: blurry.cpp bmplib.o AreaAverageMethod.o BlurryMethod.o ColorAverageArea.o RandomPixelMethod.o
	$(CC) $(CFLAGS) blurry.cpp bmplib.o AreaAverageMethod.o BlurryMethod.o ColorAverageArea.o RandomPixelMethod.o -o blurry

.cpp.o:
	$(CC) $(CFLAGS) -c $<

bmplib.o : bmplib.h

AreaAverageMethod.o: AreaAverageMethod.h bmplib.o bmplib.h

BlurryMethod.o: BlurryMethod.h bmplib.o

ColorAverageArea.o: ColorAverageArea.h

RandomPixelMethod.o: RandomPixelMethod.h AreaAverageMethod.o

clean:
	rm -f *.o *.bmp