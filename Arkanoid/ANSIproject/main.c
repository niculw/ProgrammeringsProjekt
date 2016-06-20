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
#include "help.h"

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
}


void main() {
	char i = 0, j = 0, menuPunkt = 1, menuSelector = 0;
	char status;
	char oldkey = 0 , newkey;
	keysetup();						// sæt registre til knapperne
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	resetbgcolor;
	initTimer0();
	printf("%c[?25l",0x1B);			// fjerner kurseren
	clrscr();
	initMenu();
	menuSel(menuPunkt);
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
					if (menuSelector < 3){
						menuSel(menuPunkt);		
					}
				} else if ( 2 == newkey ) {
					if (menuSelector < 2) {
						switch ( menuPunkt ) {
							 case 1 :
							 	if ( 0 == menuSelector ) {					// vi er i hovedmenuen
									game();
								} else if ( 2 == menuSelector) {			// vi er i Highscore menuen
									
								} else if ( 1 == menuSelector) {			// vi er i help menuen
									clrscr();
									printHelp( 1 );					// print control help
									menuSelector = 3;
								}
								break;
							 case 2 :		
							 	if ( 0 == menuSelector ) {					// vi er i hovedmenuen
								//	clrscr();
								//	menuSelector = 2;
									// gå til highscore
								} else if ( 2 == menuSelector) {			// vi er i Highscore menuen
									
								} else if ( 1 == menuSelector) {			// vi er i help menuen
									clrscr();
									printHelp( 2 );					// print power up help
									menuSelector = 4;
								} else {
									clrscr();
									menuSelector = 1;
								}
							 	break;
							 case 3 : 		
							 	if ( 0 == menuSelector ) {					// vi er i hovedmenuen
									clrscr();
									menuSelector = 1;
									initHelp();
									menuSel(menuPunkt);
									// gå til help menu
								} else if ( 2 == menuSelector) {			// vi er i Highscore menuen
									
								} else if ( 1 == menuSelector) {			// vi er i help menuen
									clrscr();
									initMenu();
									menuSel(menuPunkt);
									menuSelector = 0;
								}
							 	break; 
						}
					} else if ( menuSelector == 2 ){
					//	clrscr();
					} else {
						clrscr();
						initHelp();
						menuSel(menuPunkt);
						menuSelector = 1;
					}
				} else if ( 4 == newkey ) {
					if (menuPunkt < 3){
						menuPunkt++;
					} else {
						menuPunkt = 1;
					}
					if (menuSelector < 2){
						menuSel(menuPunkt);	
					}
				}
			}
		} 
//		else {	////// hvis vi ikke trykker på knappen.
//			halfMilisec = 0;
//		}
	} while (1 != 2);
}

