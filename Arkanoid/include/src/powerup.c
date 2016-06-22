#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "defines.h"
#include "powerup.h"



//srand(time(NULL));



void initPowerup( struct BallPos * ball, struct powerup * p ){
	(*p).x = (*ball).x // initates the powerup at x-coordinate
	(*p).y = (*ball).y; // initates the powerup at y-coordinate
	(*p).xV = 0;  // NO change in X-coordinate
	(*p).yV = 1; //powerup starts out by dropping
	gotoxy( (*p).x, (*p).y);
}

void drawPowerup(char select){
	gotoxy((*p).x ,(*p).y); //goes to old powerup position
	printf("%c", 32 );						// removes the old powerup
	(*p).x = (*p).x + (*p).xV ;	// generates new X position
	(*p).y = (*p).y + (*p).yV ;	// generates new Y position
	gotoxy((*p).x,(*p).y); 			// goes to new powerup position
	printf("%c", select); 						// prints the powerup at the new position

}
void despawn((struct powerup * p){
	(*p).xV = 0;  // NO change in X-coordinate
	(*p).yV = 0; //powerup starts out by dropping
	gotoxy( (*p).x, (*p).y);
		printf("%c", 32 );	
	}


void powerup(int bh,struct powerup * p, struct lives * L, collisionDetect, int STRIKER_WIDTH, struct BallPos * ball);
	if (bh == 1){
		int r = rand(15); // random tal
		if (r == 8){
			initPowerup();
			drawPowerup(40);

			if (collisionDetect > 10){
				addLife();
			}
		}

		else if (r == 9){
			initPowerup();
			drawPowerup(2F);
			if (collisionDetect > 10){
				STRIKER_WIDTH = STRIKER_WIDTH - 5;
			}
		}

		else if (r == 10){
		initPowerup();
		drawPowerup(2B);
		if (collisionDetect > 10){
		STRIKER_WIDTH = STRIKER_WIDTH + 5;
 			}
		}

		else if (r == 11){
		initPowerup();
		drawPowerup(2A);
		if (collisionDetect > 10){
		initBall();
		while (collisionDetect > 0) {
		drawBall();
		}
 		}
		}

		else if (r == 12){
		initPowerup();
		drawPowerup(246);
		if (collisionDetect > 10){
		(*L).Lives--;
}
		} 

		else if (r == 13){
		initPowerup();
		drawPowerup(253);

if (collisionDetect > 10){
		(*ball).xV = (*ball).xV / 2;
		(*ball).yV = (*ball).yV / 2;
}
		}

		else if (r == 14){
		initPowerup();
		drawPowerup(171);
		if (collisionDetect > 10){
		(*ball).xV = (*ball).xV * 2;
		(*ball).yV = (*ball).yV * 2;

		}
		}


if (collisionDetect == -1 || collisionDetect > 10){
	despawn(); 
}

button = 0;
}





		
