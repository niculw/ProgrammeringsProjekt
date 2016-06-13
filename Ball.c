#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "Ball.h"

struct BallPos{
    int x,y;
	int xV, yV;
}

void initBall(){
	struct BallPos ball;
		ball->x = 80; // initates the ball at x-coordinate
		(*ball).y = 40; // initates the ball at y-coordinate

		(*ball).xV = 0;  //No change in x-coordinate until striker is hit
		(*ball).yV = -1; //Ball starts out by dropping
		gotoxy( (*ball).x, (*ball).y);
		printf("%c", 233);
}

void drawBall(struct Ballpos * ball, int x, int y, int xV, int yV){
	(*ball).x = (*ball).x + (*ball).xV // generates new X position

	(*ball).y = (*ball).y + (*ball).yV // generates new Y position

	gotoxy((*ball).x,(*ball).y); // goes to new ball position

	printf("%c", 233);  // prints the ball at the new position
	
	gotoxy((*ball).x -(*ball).xV ,(*ball).y-(*ball).yV) //goes to old ball position

	printf("%c", 32 // removes the old ball

}
	
