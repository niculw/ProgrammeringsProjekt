#include <time.h>
#include <stdlib.h>



srand(time(NULL));


void initPowerup(struct BallPos * ball,struct powerup * p ){
	(*p).x = (*ball).x // initates the powerup at x-coordinate
	(*p).y = (*ball).y; // initates the powerup at y-coordinate
	(*p).xV = 0;  // NO change in X-coordinate
	(*p).yV = 1; //powerup starts out by dropping
	gotoxy( (*p).x, (*p).y);
	printf("%c", 40);
}

void drawPowerup(struct powerup * p){
	gotoxy((*p).x ,(*p).y); //goes to old powerup position
	printf("%c", 32 );						// removes the old powerup
	(*p).x = (*p).x + (*p).xV ;	// generates new X position
	(*p).y = (*p).y + (*p).yV ;	// generates new Y position
	gotoxy((*p).x,(*p).y); 			// goes to new powerup position
	printf("%c", 40); 						// prints the powerup at the new position
}
void powerup(int bh,struct powerup * p, struct lives * L, collisionDetect, int STRIKER_WIDTH, BallPos * ball);
	if (bh == 1){
		int r = rand(10); // random tal
		if (r == 10){
		if (collisionDetect > 10){
		(*L).Lives++;
		}
		}
		else if (r == 7){
		if (collisionDetect > 10){
		STRIKER_WIDTH = STRIKER_WIDTH - 5;
		}
		}
		else if (r == 8){
		if (collisionDetect > 10){
		STRIKER_WIDTH = STRIKER_WIDTH + 5;
 			}
		}
		else if (r == 9){
		if (collisionDetect > 10){
		initBall();
		while (collisionDetect > 0) {
		drawBall();
		}
 		}
		}
		else if (r == 10){
		if (collisionDetect > 10){
		(*L).Lives--;
}
}
}




		
