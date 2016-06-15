#include "defines.h"
#include "ansi.h"
#include "initLevel.h"
#include "Striker.h"
#include "ball.h"
#include "collisionDetect.h"
#include "angleCalc.h"
#include "io.h"
#include "life.h"

void game(){
	int knapKonstant = 0, k = 0;
	short strikerPosition = STRIKER_START_POSITION;		/// vi starter på midsten af skærmen
	char oldkey = 0 , newkey;
	struct BallPos ball;
	struct lives life;
	color(1,0);
	clrscr();
	drawBorder(2);
	initStriker();
	initBall( &ball , strikerPosition);
	initLife( &life );
	do {
		newkey = readKey();
		if( 0 != newkey ){											// hvis vi har trykket på en knap
			if ( knapKonstant == 0 ) {								
				knapKonstant = 500;
				if ( 1 == newkey && strikerPosition < RESOLUTION_X - STRIKER_WIDTH ){
				///// right key pressed
					strikerPosition++;
				} else if ( 4 == newkey && strikerPosition > 2) {
				///// left key pressed
					strikerPosition--;
				} else if (2 == newkey){
					ball.ballStarted = 1;
				}
				if ( ball.ballStarted == 0){
					drawBall( &ball , strikerPosition);		//// bolden følger strikerens position
				}
				drawStriker( strikerPosition );
			} else {
				knapKonstant--;
			} 
		} else {
			knapKonstant = 0;
		}
		if (k == 5000){
			drawBall( &ball , strikerPosition);
			angleCalculation( &ball , collisionDetect( &ball, strikerPosition , &life) );
		//	gotoxy( 10, 57);
		//	printf("Collision: %d \n",collisionDetect( &ball, strikerPosition )  );
			k = 0;
		} else {
			k++;
		}
	} while ( 1 != 2 );

}
