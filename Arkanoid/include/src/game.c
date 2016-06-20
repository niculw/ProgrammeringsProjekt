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
#include "block.h"

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
	short k = 0, level = 1;
	short strikerPosition = STRIKER_START_POSITION;		/// vi starter på midsten af skærmen
	char oldkey = 0 , newkey;
	char blocks[25][22];
	struct BallPos ball;
//	struct lives life;
	struct block b[NUM_BLOCKS];
	struct controlData ctrlData;
	color(1,0);
	clrscr();
	drawBorder(2);
	initStriker();
	initControl( &ctrlData );
	initBall( &ball );
//	initLife( &life );
	initLevel( blocks , &ctrlData);
	printBlocks( blocks, &ctrlData );
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
			if ( 0 == k ) {
				drawBall( &ball , strikerPosition );		//// opdater bolden og læg vektor til
				////////// regn ny vektor hvis der er en kollision
				angleCalculation( &ball , collisionDetect( &ball, strikerPosition , blocks, &ctrlData ) );
				printControlData( &ctrlData );
				k = 0;
			} else {
				k++;
			}
			halfMilisec = 0;
	    }
	} while ( 1 != 2 );
}
