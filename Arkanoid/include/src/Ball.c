#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
//#include "Ball.h"

struct BallPos{
    int x,y;
	int xV, yV;
};

void initBall( struct BallPos * ball ){
	(*ball).x = 80; // initates the ball at x-coordinate
	(*ball).y = 40; // initates the ball at y-coordinate
	(*ball).xV = 1;  //No change in x-coordinate until striker is hit
	(*ball).yV = 0; //Ball starts out by dropping
	gotoxy( (*ball).x, (*ball).y);
	printf("%c", 111);
}

void drawBall(struct BallPos * ball){
	gotoxy((*ball).x ,(*ball).y); //goes to old ball position
	printf("%c", 32 );						// removes the old ball
	(*ball).x = (*ball).x + (*ball).xV ;	// generates new X position
	(*ball).y = (*ball).y + (*ball).yV ;	// generates new Y position
	gotoxy((*ball).x,(*ball).y); 			// goes to new ball position
	printf("%c", 111); 						// prints the ball at the new position
}
	