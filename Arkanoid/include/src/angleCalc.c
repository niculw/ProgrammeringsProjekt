#include "lut.h"

struct BallPos{
    int x,y;
	int xV, yV;
};

void angleCalculation( struct BallPos * ball , int collision ){
	switch (collision) {
		case 1 :
			(*ball).xV = -(*ball).xV;
			break;
		case 2 :
			(*ball).yV = -(*ball).yV;
			break;
		case 3 :
			(*ball).yV = - (*ball).yV;
			break;
		case 4 :
			(*ball).yV = - (*ball).yV;
			break;
		case 5 :
			(*ball).yV = - (*ball).yV;
			break;
		case 6 :
			(*ball).yV = - (*ball).yV;
			break;
		case 7 :
			(*ball).yV = - (*ball).yV;
			break;
	}
}
