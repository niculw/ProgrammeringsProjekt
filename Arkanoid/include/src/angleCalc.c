#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "angleCalc.h"
#include "defines.h"

struct BallPos{
    long x,y;
	long xV, yV;
};

void angleCalculation( struct BallPos * ball , unsigned char collision ){
	switch (collision) {
		case 0 :								/// no collision
			break;
		case 1 :								/// window sides hit OR block sides hit
			(*ball).xV = -(*ball).xV;
			break;
		case 2 :								/// window top hit OR block button/top hit
			(*ball).yV = -(*ball).yV;
			break;
		case 3 :								/// left striker hit
			if ( 0 <= (*ball).xV ) {		// bolden kommer fra venstre
				(*ball).xV = -8192;
				(*ball).yV = -14188;
			} else {							// bolden kommer fra højre
				(*ball).xV = -15825;
				(*ball).yV = -4240;
			}
			break;
		case 4 :								/// left middle striker hit
			if ( 0 <= (*ball).xV ) {		// fra venstre
				(*ball).xV = -4240;
				(*ball).yV = -15825;
			} else {							// fra højre
				(*ball).xV = -8192;
				(*ball).yV = -14188;
			}
			break;
		case 5 :								/// center striker hit
			(*ball).yV = - (*ball).yV;			// 90 grader
			break;
		case 6 :								/// right middle striker hit
			if ( 0 <= (*ball).xV ) {		// fra venstre
				(*ball).xV = 14188;
				(*ball).yV = -8192;
			} else {							// fra højre
				(*ball).xV = 4240;
				(*ball).yV = -15825;
			}
			break;
		case 7 :								/// right striker hit
			if ( 0 <= (*ball).xV ) {		// fra venstre
				(*ball).xV = 15825;
				(*ball).yV = -4240;
			} else {							// fra højre
				(*ball).xV = 8192;				// 60 grader
				(*ball).yV = -14188;
			}
			break;
		case 8 :
			(*ball).xV = -(*ball).xV;
			(*ball).yV = -(*ball).yV;
			break;
	}
}
