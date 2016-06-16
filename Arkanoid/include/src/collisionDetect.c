
#include "defines.h"
#include "life.h"
#include "ball.h"

int collisionDetect( struct BallPos * ball, short strikerPos , struct lives * life){
	if ( (*ball).x >> 14 <= 2 || (*ball).x >> 14 >= RESOLUTION_X - 1 ){	// window sides hit
		return 1;
	} else if ( (*ball).y >> 14 <= 2) {							// window top hit
		return 2;
	} else if ( (*ball).y >> 14 >= RESOLUTION_Y - 2 ) {			// possable stikrer hit
		if ( (*ball).x >> 14 >= strikerPos && (*ball).x >> 14 <= strikerPos + ( STRIKER_WIDTH / 5 ) - 1 ){
			return 3;										// hit left 
		} else if ( (*ball).x >> 14 > strikerPos + ( STRIKER_WIDTH / 5 ) - 1 
					&& (*ball).x >> 14 <= strikerPos + 2 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 4;										// hit left middle
		} else if ( (*ball).x >> 14 > strikerPos + 2 * ( STRIKER_WIDTH / 5 ) - 1 
					&& (*ball).x >> 14 <= strikerPos + 3 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 5;										// hit middle
		} else if ( (*ball).x >> 14 > strikerPos + 3 * ( STRIKER_WIDTH / 5 ) - 1 
					&& (*ball).x >> 14 <= strikerPos + 4 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 6;										// hit right middle
		} else if ( (*ball).x >> 14 >  strikerPos + 4 * ( STRIKER_WIDTH / 5 ) - 1 
					&& (*ball).x >> 14 <= strikerPos + 5 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 7;										// hit right
		} else {											// didnt hit striker (dead)
			lifeChanger( life );
			despawn( ball );
			initBall( ball );
			return -1;										// striker not hit
		}
	} else if ( 1 != 1 ) {									// hit block button or top
			//// dummy
		return 8;											
	} else if ( 1 != 1 ) {									// hit block sides
			//// dummy 
		return 9;											
	} else if ( 1 != 1 ) {									// hit block edges
			//// dummy
			//// if x + xV == block start or end
			//// && if y + yV == block start or end at y
		return 10;											
	} else {
		return 0;
	}
}