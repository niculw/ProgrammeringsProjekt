#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "defines.h"  
#include "game.h"
#include "ansi.h"
#include "initLevel.h"
#include "Striker.h"
#include "ball.h"
#include "collisionDetect.h"
#include "angleCalc.h"
#include "io.h"
#include "life.h"
#include "LED.h"
#include "menu.h"


extern int halfMilisec ;

void initControl( struct controlData * ctrlData ){
	(*ctrlData).point = 0;
	(*ctrlData).level = 1;
	(*ctrlData).blockCount = 0;
	(*ctrlData).playerLife = 3;
	
	printLife( ctrlData );
	
}

void printControlData( struct controlData * ctrlData ){
	color(7,0);
	gotoxy(165,40);
	printf("Points: %4d",(*ctrlData).point );
	gotoxy(165,41);
	printf("Blocks left: %3d",(*ctrlData).blockCount);
	gotoxy(165,42);
	printf("Level: %2d", (*ctrlData).level);
} 
void game() {
	unsigned char k = 0, m = 0, strikerPosition = STRIKER_START_POSITION;		/// vi starter på midsten af skærmen
	unsigned char oldkey = 0, newkey, gameStarted = 1;
	char blocks[25][22];
	struct BallPos ball;
	struct controlData ctrlData;
	LEDinit();
	clrscr();
	drawBorder(2);
	initStriker();
	initControl( &ctrlData );
	initBall( &ball );
	initLevel( blocks, &ctrlData );
	printBlocks( blocks, &ctrlData );
	printControlData( &ctrlData );
	initVideoBuffer( &ctrlData );
	do {
		LEDupdate( &ctrlData );
		if ( halfMilisec >= 64 ) {								// general timing speed, depends on code speed
			newkey = readKey();
			if ( m == 0 ){										// offset for striker speed, higher == slower striker
				if( 0 != newkey ) {								// hvis vi har trykket på en knap						
					if ( 1 == newkey && strikerPosition < RESOLUTION_X - STRIKER_WIDTH ){
					///// right key pressed
						strikerPosition++;
					} else if ( 4 == newkey && strikerPosition > 2 ) {
					///// left key pressed
						strikerPosition--;
					} else if ( 2 == newkey ) {
						if ( ctrlData.playerLife > 0 ){	// start the ball
							ball.ballStarted = 1;	
						} else {						
							gameStarted = 0;
							clearLevel();				// only for visuel effects
							clrscr();
							initMenu();	
							menuSel( 1 );
						}
					}
					if ( ball.ballStarted == 0 && ctrlData.playerLife > 0 ) {
						drawBall( &ball , strikerPosition);		//// bolden følger strikerens position
					}
					drawStriker( strikerPosition );
				}
				m = 0;
			} else {
				m++;
			}
			if ( 0 == k && gameStarted == 1) {									// offset for ball speed, higher == slower
				drawBall( &ball , strikerPosition );		//// opdater bolden og læg vektor til
				////////// regn ny vektor hvis der er en kollision
				angleCalculation( &ball , collisionDetect( &ball, strikerPosition , blocks, &ctrlData ) );
				if ( ctrlData.blockCount == 0 && ball.ballStarted == 1){	// time for next level
					ball.ballStarted = 0;
					despawn( &ball );
					drawBall( &ball , strikerPosition );
					if ( ctrlData.level < 4 ) {			// we only hae 4 levels!
						clearLevel();
						addLife( &ctrlData );
						ctrlData.level++;
						initLevel( blocks , &ctrlData );
						printBlocks( blocks, &ctrlData );
						printControlData( & ctrlData );
					} else {							// end of level 4
						printWin( &ctrlData );
						if ( 2 == newkey ){
							gameStarted = 0;
							clearLevel();				// only for visuel effects
							clrscr();
							initMenu();	
							menuSel( 1 );
						}
					}
				}
				k = 0;
			} else {
				k++;
			}
			halfMilisec = 0;
	    }
	} while ( 1 == gameStarted );
}
