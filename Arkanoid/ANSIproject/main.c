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
#include "game.h"
#include "io.h"
#include "menu.h"

void main() {
	int i = 0, j = 0, menuPunkt = 1, knapKonstant = 0;
	char status;
	char oldkey = 0 , newkey;
	keysetup();						// sæt registre til knapperne
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	printf("%c[?25l",0x1B);			// fjerner kurseren
	clrscr();
	initMenu();
//	color(1,0);
//	LEDinit();

//	printBlocks(&b, 2, 2, 4);

	do {
		
	//	printf("while main");

		newkey = readKey();
		if( 0 != newkey ){											// hvis vi ahr trykket på en knap
			if ( knapKonstant == 0 ) {								
				knapKonstant = 50000;
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
			} else {
				knapKonstant--;
			} 
		} else {
			knapKonstant = 100;
		}


		if (1 == 2){
		
		} else if (1 == 2){
			game();
		}
	} while (1 != 2);
}

