#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "Ball.h"

void initBall( struct BallPos * ball, short strikerPosition ){
	(*ball).x = ( strikerPosition + 7 ) << 14; // initates the ball at x-coordinate
	(*ball).y = 59 << 14; // initates the ball at y-coordinate
	(*ball).xV = 1 << 14;  //No change in x-coordinate until striker is hit
	(*ball).yV = 1 << 14; //Ball starts out by dropping
	ball->ballStarted = 0;
	color(6,0);
	gotoxy( (*ball).x >> 14, (*ball).y >> 14);
	printf("%c", 111);
}

void despawn(struct BallPos * ball, short strikerPosition){
	gotoxy( (*ball).x >> 14, (*ball).y >> 14 );
	printf("%c", 32 );	
	initBall( ball , strikerPosition);
}

void drawBall(struct BallPos * ball, short strikerPosition ){
	if ( (*ball).ballStarted == 1){
		color(6,0);
		gotoxy((*ball).x >> 14 ,(*ball).y >> 14); 	//goes to old ball position
		printf("%c", 32 );							// removes the old ball
		(*ball).x = (*ball).x + (*ball).xV ;		// generates new X position
		(*ball).y = (*ball).y + (*ball).yV ;		// generates new Y position
		gotoxy((*ball).x >> 14 ,(*ball).y >> 14); 	// goes to new ball position
		printf("%c", 111); 							// prints the ball at the new position
	} else {
		color(11,0);
		gotoxy((*ball).x >> 14 ,(*ball).y >> 14); 	//goes to old ball position
		printf("%c", 32 );							// removes the old ball
		(*ball).x = (long) strikerPosition + 7 << 14;						// generates new X position
		(*ball).y = 59 << 14;						// generates new Y position
		gotoxy((*ball).x >> 14 ,(*ball).y >> 14); 	// goes to new ball position
		printf("%c", 111); 							// prints the ball at the new position
	}
}

