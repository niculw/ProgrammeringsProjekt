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

#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / (b) )

struct TVector {
	long x,y;
};

struct BallPos{
    int x,y;
	int xV, yV;
};

long expand(long i) {
	// converts an 18.14 to a 16.16
	return i << 2;
}

void printFix(long i) {
	// prints a signed 16.16 fixed point number
	if ((i & 0x80000000) != 0) { // handle negative numbers
		printf("-");
		i = ~i+1;
	}
	printf("%ld.%04ld", i >> 16, 10000 * (unsigned long) (i & 0xffff) >> 16);
	// max 4 digits otherwise we get overflow
}

void initVector(struct TVector * v, long x, long y){
	(*v).x = x << 14;
	(*v).y = y << 14;
	printf("input: %ld,%ld\n", x, y );
	printf("stored: (%ld,%ld)\n",(*v).x ,(*v).y);
}

void rotate(struct TVector * v, int a ){
	long x = (*v).x;
	long y = (*v).y;
	(*v).x =  (FIX14_MULT( x,  cos(a)) - FIX14_MULT( y,  sin(a) )) ;
	(*v).y =  (FIX14_MULT( x,  sin(a)) + FIX14_MULT( y,  cos(a) ))	;
}

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
				strikerPosition++;
			} else if ( 4 == newkey && strikerPosition > 2) {
				strikerPosition--;
			}
			drawStriker( strikerPosition );
		} else {
			knapKonstant--;
		} 
	} else {
		knapKonstant = 0;
	}
	
	if (k == 10000){
		drawBall( &ball );
		gotoxy( 10, 59);
		angleCalculation( &ball , collisionDetect( &ball, strikerPosition ) );
		//printf("%d \n",collisionDetect( &ball, strikerPosition )  );
		k = 0;
	} else {
		k++;
	}
	} while (1 != 2);
}

