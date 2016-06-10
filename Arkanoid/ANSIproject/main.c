#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include <string.h>

#include "ansi.h"
#include "lut.h"
//#include "charset.h"		 // indkluderet i LED.c
#include "LED.h"
#include "StopWatch.h"
#include "initLevel.h"

#define FIX14_SHIFT 2
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / (b) )



struct TVector {
	long x,y;
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
	(*v).x = expand( x );
	(*v).y = expand( y );
	printf("New Vector: %ld,%ld (%d,%d)\n", (*v).x, (*v).y, (*v).x >> 2 , (*v).y >> 2);
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
	int i;
	int k = 0, j = 0;
	char oldkey = 0 , newkey;
	char str[] = "En To";
//	struct TVector V1;
//	struct TVector V2;
//	struct TVector V3;
//	struct time watch;
//	keysetup();						// 
//	initCounter();					// initialise counter for 100 hz refresh inteval.
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);

	color(1,0);
	gotoxy(1,1);
	clrscr();
	
	LEDinit();

	drawBorder(2);

	//EI();
	//window(2, 2, 25, 7, "Hej You ", 0);
//	window(5, 5, 40, 12, "Stop Watch  ", 1);
	
	//LEDsetString("123456789abcdefghijlk");

//	inittime( &watch ,0 ,0 ,0 ,0, 0);

/*	initVector( &V1 , 40 , 0 );
	rotate( &V1 , 128 );
	printf("After rotation: %d,%d\n", V1.x  >> 14 , V1.y >> 14);
*/
	do {
	LEDupdate();
	mellemled( str , strlen(str) );
	

	/*
	if ( ( newkey != 0) && (oldkey != newkey) ){
			k++;
			gotoxy(3,3);
			printf("%d", k );
			oldkey = newkey;
		} else if (newkey == 0) {
			oldkey = 0;
	}
	*/
//	calcTime( &watch );
//	ledcontrol( k );
//	printtime( &watch );
	//T0CTL |= 0x81;			// enable timer // 1001 1001
	//printf("Timeren er %d , d \n", T0H , T0L );
	} while (1 != 2);
}

