#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "lut.h"
#include "angleCalc.h"
#include "defines.h"

struct BallPos{
    int x,y;
	int xV, yV;
};

long expand(long i) {
	// converts an 18.14 to a 16.16
	return i << 2;
}

void printFix(long i) {
	// prints a signed 16.16 fixed point number
	if ((i & 0x80000000) != 0) { // handle negative numbers
		printf("-");
		i = ~i+1;
	}
	printf("%ld.%04ld", i >> 16, 10000 * (unsigned long) (i & 0xffff) >> 16);
	// max 4 digits otherwise we get overflow
}

void initVector(struct TVector * v, long x, long y){
	(*v).x = x << 14;
	(*v).y = y << 14;
	printf("input: %ld,%ld\n", x, y );
	printf("stored: (%ld,%ld)\n",(*v).x ,(*v).y);
}

void rotate(struct TVector * v, int a ){
	long x = (*v).x;
	long y = (*v).y;
	(*v).x =  (FIX14_MULT( x,  cos(a)) - FIX14_MULT( y,  sin(a) )) ;
	(*v).y =  (FIX14_MULT( x,  sin(a)) + FIX14_MULT( y,  cos(a) ))	;
}

void angleCalculation( struct BallPos * ball , int collision ){
	switch (collision) {
		case 1 :								/// top hit
			(*ball).xV = -(*ball).xV;
			break;
		case 2 :								/// sides hit
			(*ball).yV = -(*ball).yV;
			break;
		case 3 :								/// left striker hit
			(*ball).yV = - (*ball).yV;
			break;
		case 4 :								/// left middle striker hit
			(*ball).yV = - (*ball).yV;
			break;
		case 5 :								/// middle striker hit
			(*ball).yV = - (*ball).yV;
			break;
		case 6 :								/// right middle striker hit
			(*ball).yV = - (*ball).yV;
			break;
		case 7 :								/// right striker hit
			(*ball).yV = - (*ball).yV;
			break;
	}
}
