#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "lut.h"
#include "ansi.h"
#include "angleCalc.h"
#include "defines.h"

struct BallPos{
    long x,y;
	long xV, yV;
};
/*
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
*/
void rotate(struct BallPos * ball, int a ){
	long xV = (*ball).xV;
	long yV = (*ball).yV;
	(*ball).xV =  (FIX14_MULT( xV,  cos(a)) - FIX14_MULT( yV,  sin(a) )) ;
	(*ball).yV =  (FIX14_MULT( xV,  sin(a)) + FIX14_MULT( yV,  cos(a) )) ;
}

void angleCalculation( struct BallPos * ball , int collision ){
	switch (collision) {
		case 0 :								/// no collision
			break;
		case 1 :								/// window sides hit
			(*ball).xV = -(*ball).xV;
			break;
		case 2 :								/// window top hit
			(*ball).yV = -(*ball).yV;
			break;
		case 3 :								/// left striker hit
		//	(*ball).xV = (*ball).xV ;
		//	(*ball).yV = - (*ball).yV;
			if ( 0 <= (*ball).xV >> 14 ) {		// bolden kommer fra venstre eller oppefra
				rotate( ball , 320 );			// 225 grader
			} else {							// bolden kommer fra højre
				rotate( ball , 64 );			// 45 grader
			}
			break;
		case 4 :								/// left middle striker hit
	//		(*ball).yV = - (*ball).yV;
			if ( 0 <= (*ball).xV >> 14 ) {
				rotate( ball , 288 );			// 202,5 grader
			} else {
				rotate( ball , 128 );			// 90 grader
			}

			break;
		case 5 :								/// middle striker hit
			(*ball).yV = - (*ball).yV;			// 90 grader
			break;
		case 6 :								/// right middle striker hit
	//		(*ball).yV = - (*ball).yV;
			if ( 0 <= (*ball).xV >> 14 ) {
				rotate( ball , 320 );			// 225 grader
			} else {
				rotate( ball , 192 );			// 135 grader
			}

			break;
		case 7 :								/// right striker hit
	//		(*ball).yV = - (*ball).yV;
			if ( 0 <= (*ball).xV >> 14 ) {
				rotate( ball , 384 );			// 270 grader
			} else {
				rotate( ball , 224 );			// 157.5 grader
			}

			break;
	}
}
