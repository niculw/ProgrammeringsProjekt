//#define RESOLUTION_X 171
//#define RESOLUTION_Y 61
//#define STRIKER_WIDTH 15		// skal kunne deles med 5
#include "defines.h"

struct BallPos{
    int x,y;
	int xV, yV;
};

int collisionDetect( struct BallPos * ball, short strikerPos ){
	if ( (*ball).x <= 2 || (*ball).x >= RESOLUTION_X - 1 ){	// siderne ramt
		return 1;
	} else if ( (*ball).y <= 2) {							// topbar ramt
		return 2;
	} else if ( (*ball).y >= RESOLUTION_Y - 2 ) {			// stikrer ramt
		if ( (*ball).x >= strikerPos && (*ball).x <= strikerPos + ( STRIKER_WIDTH / 5 ) - 1 ){
			return 3;										// hit left 
			
		} else if ( (*ball).x > strikerPos + ( STRIKER_WIDTH / 5 ) - 1 
					&& (*ball).x <= strikerPos + 2 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 4;										// hit left middle

		} else if ( (*ball).x > strikerPos + 2 * ( STRIKER_WIDTH / 5 ) - 1 
					&& (*ball).x <= strikerPos + 3 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 5;										// hit middle

		} else if ( (*ball).x > strikerPos + 3 * ( STRIKER_WIDTH / 5 ) - 1 
					&& (*ball).x <= strikerPos + 4 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 6;										// hit right middle

		} else if ( (*ball).x > strikerPos + 4 * ( STRIKER_WIDTH / 5 ) - 1 
					&& (*ball).x <= strikerPos + 5 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 7;										// hit right
		} else {
			return -1;										// striker not hit
		}
	} else {
		return 0;
	}
}