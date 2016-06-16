#include "defines.h"  
#include "ansi.h"
#include "initLevel.h"
#include "Striker.h"
#include "ball.h"
#include "collisionDetect.h"
#include "angleCalc.h"
#include "io.h"
#include "life.h"

extern int halfMilisec ;

void game() {
	short k = 0;
	short strikerPosition = STRIKER_START_POSITION;		/// vi starter på midsten af skærmen
	char oldkey = 0 , newkey;
	struct BallPos ball;
	struct lives life;
	color(1,0);
	clrscr();
	drawBorder(2);
	initStriker();
	initBall( &ball );
	initLife( &life );
	do {
		if ( halfMilisec >= 64 ) {
			newkey = readKey();
			if( 0 != newkey ) {								// hvis vi har trykket på en knap						
				if ( 1 == newkey && strikerPosition < RESOLUTION_X - STRIKER_WIDTH ){
				///// right key pressed
					strikerPosition++;
				} else if ( 4 == newkey && strikerPosition > 2 ) {
				///// left key pressed
					strikerPosition--;
				} else if ( 2 == newkey ) {
					ball.ballStarted = 1;					
				}
				if ( ball.ballStarted == 0 ) {
					drawBall( &ball , strikerPosition);		//// bolden følger strikerens position
				}
				drawStriker( strikerPosition );
			}
			if ( 1 == k ) {
				drawBall( &ball , strikerPosition);
				angleCalculation( &ball , collisionDetect( &ball, strikerPosition , &life) );
				k = 0;
			} else {
				k++;
			}
			halfMilisec = 0;
	    }
	} while ( 1 != 2 );
}
