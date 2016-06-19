#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "defines.h"
#include "Ball.h"

extern int halfMilisec;

void initBall( struct BallPos * ball ){
	(*ball).x = STRIKER_START_POSITION + 7 << 14; // initates the ball at x-coordinate
	(*ball).y = 58 << 14; // initates the ball at y-coordinate
	(*ball).xV = 11585; //1 << 14;  //No change in x-coordinate until striker is hit
	(*ball).yV = 11585; //1 << 14; //Ball starts out by dropping
	ball->ballStarted = 0;
}

void despawn(struct BallPos * ball ){
	gotoxy( (*ball).x >> 14, (*ball).y >> 14 );
	printf("%c", 32 );	
}

void drawBall(struct BallPos * ball, short strikerPosition ){
	int i;
	if ( (*ball).ballStarted == 1){
		color(6,0);
		gotoxy((*ball).x >> 14 ,(*ball).y >> 14); 	//goes to old ball position
		printf("%c", 32 );							// removes the old ball
		///////////////////////////////////////////////////
		//	nedenst�ende er for at korrigere for evt. langsom kode
		//  koden tjekker om den burde flytte mere end �n vektor
		// 
		// bolden kan dog godt flybe udenfor banen hvis for loopet k�rer mere end en gang. 
		// men den burde blvier f�rt tilbage p� banen i angleCalc.c
		//////////////////////////////////////////////////
		for ( i = 0; i < halfMilisec >> 6 ; i++ ) {	
			(*ball).x = (*ball).x + (*ball).xV ;		// generates new X position
			(*ball).y = (*ball).y + (*ball).yV ;		// generates new Y position
		}
		gotoxy((*ball).x >> 14 ,(*ball).y >> 14); 	// goes to new ball position
		printf("%c", 111); 							// prints the ball at the new position
	} else {
		color(11,0);
		gotoxy((*ball).x >> 14 ,(*ball).y >> 14); 	//goes to old ball position
		printf("%c", 32 );							// removes the old ball
		(*ball).x = (long) strikerPosition + 7 << 14;	// generates new X position
		(*ball).y = 58 << 14;						// generates new Y position
		(*ball).xV = 11585; 
		(*ball).yV = 11585; 
		gotoxy((*ball).x >> 14 ,(*ball).y >> 14); 	// goes to new ball position
		printf("%c", 111); 							// prints the ball at the new position
	}
}

