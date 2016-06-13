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
			
			break;
		case 4 :

			break;
		case 5 :
			(*ball).y = - (*ball).y;
			break;
		case 6 :

			break;
		case 7 :

			break;
	}
}
