#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include <string.h>
#include "defines.h"
#include "ansi.h"
#include "lut.h"
//#include "charset.h"		 // indkluderet i LED.c
#include "LED.h"
#include "StopWatch.h"
#include "initLevel.h"
#include "Striker.h"
#include "angleCalc.h"
#include "block.h"
#include "ball.h"
#include "collisionDetect.h"

char readKey(){
	char F , D , A;
	F = PFIN;
	D = PDIN;
	A = ( F >> 5 & 0x02) | (F >> 7 & 0x01 ) | ( D >> 1 & 0x04);
	return (~A & 0x07);
}

void keysetup(){
	PFDD |= 0xC0; 
	PDDD |= 0x08; 
}

void ledcontrol( int number ){
	PEDD = 0x0F;     // 1 for input 0 for output
	PGDD = 0x00;
	PGOUT = number;
	PEOUT |= 0x40;
	PEOUT &= 0xBF;
}

void main() {
	int i, knapKonstant = 0;
	int k = 0, j = 0;
	short strikerPosition = 80;		/// vi starter på midsten af skærmen
	char oldkey = 0 , newkey;
//	char str[] = "ELEKTRO!!";
	struct BallPos ball;
	keysetup();						// sæt registre til knapperne
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	printf("%c[?25l",0x1B);			// fjerner kurseren

	color(1,0);
	gotoxy(1,1);
	clrscr();
//	LEDinit();

	drawBorder(2);
	initStriker();
	initBall( &ball );
//	printBlocks(&b, 2, 2, 4);

	do {
	newkey = readKey();
	if( 0 != newkey ){											// hvis vi ahr trykket på en knap
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
				drawBall( &ball , strikerPosition);
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
		angleCalculation( &ball , collisionDetect( &ball, strikerPosition ) );
		gotoxy( 10, 57);
	//	printf("Collision: %d \n",collisionDetect( &ball, strikerPosition )  );
		k = 0;
	} else {
		k++;
	}
	} while (1 != 2);
}

