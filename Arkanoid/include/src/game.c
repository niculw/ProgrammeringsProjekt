#include "defines.h"  
#include "ansi.h"
#include "initLevel.h"
#include "Striker.h"
#include "ball.h"
#include "collisionDetect.h"
#include "angleCalc.h"
#include "io.h"
#include "life.h"
#include "block.h"

extern int halfMilisec ;

void game() {
	short k = 0, level = 1;
	short strikerPosition = STRIKER_START_POSITION;		/// vi starter på midsten af skærmen
	char oldkey = 0 , newkey;
	char blocks[25][20];
	struct BallPos ball;
	struct lives life;
	struct block b[NUM_BLOCKS];
	color(1,0);
	clrscr();
	drawBorder(2);
	initStriker();
	initBall( &ball );
	initLife( &life );
	initLevel( blocks , level);
	printBlocks( blocks );
//	initLevels(b, level);
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
				drawBall( &ball , strikerPosition );		//// opdater bolden og læg vektor til
				////////// regn ny vektor hvis der er en kollision
				angleCalculation( &ball , collisionDetect( &ball, strikerPosition , &life, blocks ) );
				k = 0;
			} else {
				k++;
			}
			halfMilisec = 0;
	    }
	} while ( 1 != 2 );
}
