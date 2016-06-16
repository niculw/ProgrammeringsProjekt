#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include <string.h>
#include "defines.h"
#include "ansi.h"
#include "lut.h"
//#include "charset.h"		 // indkluderet i LED.c
//#include "LED.h"
//#include "StopWatch.h"
#include "initLevel.h"
#include "Striker.h"
#include "angleCalc.h"
#include "block.h"
#include "ball.h"
#include "collisionDetect.h"
#include "game.h"
#include "io.h"
#include "menu.h"
//#include "life.h"

int halfMilisec = 0;

#pragma interrupt 
void timer0int() { 
	halfMilisec += 1;
}

void initTimer0() {
	DI();					// disable inteupt
	//////////////////////////////////////////////////// setup interupts to low prioritet
	SET_VECTOR(TIMER0, timer0int);
	IRQ0ENH &= 0x00;		// low prioitet
	IRQ0ENL |= 0x20;		// low prioitet
	//////////////////////////////////////////////////// timer 0 config to 0.5ms interval
	T0RH = 0x24;			// set reload high value 
	T0RL = 0x00;			// set reload low value
	T0H = 0x00;				// timer byte high = 00000000
	T0L = 0x01;				// timer byte low = 00000001
	T0CTL = 0x81;			// 1000 0001 // enable and continious mode
	//////////////////////////////////////////////////// 
	EI();					// enable interupts
	//T0CTL |= 0x99;		// enable timer // 1001 1001
}


void main() {
	int i = 0, j = 0, menuPunkt = 1; //, knapKonstant = 0;
	char status;
	char oldkey = 0 , newkey;
	keysetup();						// sæt registre til knapperne
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	initTimer0();
	printf("%c[?25l",0x1B);			// fjerner kurseren
	clrscr();
	initMenu();

//	color(1,0);
//	LEDinit();

//	printBlocks(&b, 2, 2, 4);

	do {
		newkey = readKey();
		if( 0 != newkey ) {					// hvis vi har trykket på en knap
			if ( halfMilisec > 500 ) {								
				halfMilisec = 0;
				if ( 1 == newkey ){
					if (menuPunkt > 1){
						menuPunkt--;
					} else {
						menuPunkt = 3;
					}
					menuSel(menuPunkt);		////////////// kan denne måske placeres uden for if sætningen?
				} else if ( 2 == newkey ) {
					switch ( menuPunkt ) {
						 case 1 :
							game();
							break;
						 case 2 :
							//// menuPunkt 2 goes here
						 	break;
						 case 3 : 
							//// menuPunkt 3 goes here
						 	break;
					}
				} else if ( 4 == newkey ) {
					if (menuPunkt < 3){
						menuPunkt++;
					} else {
						menuPunkt = 1;
					}
					menuSel(menuPunkt);		 ////////////// kan denne måske placeres uden for if sætningen?
				}
			}
		} 
//		else {	////// hvis vi ikke trykker på knappen.
//			halfMilisec = 0;
//		}
	} while (1 != 2);
}

