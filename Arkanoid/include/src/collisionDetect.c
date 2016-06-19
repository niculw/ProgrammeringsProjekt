#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

#include "defines.h"
#include "life.h"
#include "ball.h"
#include "ansi.h"

int collisionDetect( struct BallPos * ball, short strikerPos , struct lives * life, char blocks[25][22] ){
	static int debug = 1;
	int ballX = (*ball).x >> 14;
	int ballY = (*ball).y  >> 14;
	int ballXOffset = ballX + 6;
	int ballXArray = ballXOffset >> 3 ;		// for blok detection, >> 14 for omregning til heltal, og >> 3 for omregning til blok array. da hver blok er 2^3 bred
	int ballYArray = ballY >> 1;			// for blok detection, >> 14 for omregning til heltal, og >> 1 for omregning til blok array, da hver blok er 2^1 høj.
	gotoxy(5,62);
	printf("ball Pos: %2d %2d",ballX, ballY );
	gotoxy(5,63);
	printf("ball Array Pos: %2d %2d",ballXArray, ballYArray );
	if ( ballX <= 2 || ballX >= RESOLUTION_X - 1 ){	// window sides hit
		return 1;
	} else if ( ballY <= 2) {							// window top hit
		return 2;
	} else if ( ballY >= RESOLUTION_Y - 2 ) {			// possable stikrer hit
		if ( ballX>= strikerPos && ballX <= strikerPos + ( STRIKER_WIDTH / 5 ) - 1 ){
			return 3;										// hit left 
		} else if ( ballX > strikerPos + ( STRIKER_WIDTH / 5 ) - 1 
					&& ballX <= strikerPos + 2 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 4;										// hit left middle
		} else if ( ballX > strikerPos + 2 * ( STRIKER_WIDTH / 5 ) - 1 
					&& ballX <= strikerPos + 3 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 5;										// hit middle
		} else if ( ballX > strikerPos + 3 * ( STRIKER_WIDTH / 5 ) - 1 
					&& ballX <= strikerPos + 4 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 6;										// hit right middle
		} else if ( ballX >  strikerPos + 4 * ( STRIKER_WIDTH / 5 ) - 1 
					&& ballX <= strikerPos + 5 * ( STRIKER_WIDTH / 5 ) - 1 ) {
			return 7;										// hit right
		} else {											// didnt hit striker (dead)
			removeLife( life );
			despawn( ball );
			initBall( ball );
			return -1;										// striker not hit
		}
	} else if ( ( ballY ) < 50 ){						// check if ball is inside block array
		if ((*ball).yV > 0 ) {												// yV positiv
			if ( (*ball).xV > 0 ) {											// xV og yV er positive
				/*	gotoxy(175,debug);
					printf(" y + x +");
					debug++;*/
				if ( (( ballXOffset + 1 ) >> 3 ) != ballXArray ) {		// så står der en blok til højre for bolden
					if ( (( ballY + 1 ) >> 1 ) != ballYArray ) {	// så står der OGSÅ en blok under bolden
						if ( ( blocks[ ballYArray ][ ballXArray + 1 ] && 0x01 == 0x01 )
							&& ( blocks[ ballYArray + 1 ][ ballXArray ] && 0x01 == 0x01  ) ){	// er der noget på disse positioner
							return 8;										// vend 180 grader
						} else if ( blocks[ ballYArray ][ ballXArray + 1 ] && 0x01 == 0x01 ) {		// der er kun en aktiv blok til højre for blokken
							return 1;
						} else if ( blocks[ ballYArray + 1 ][ ballXArray ] && 0x01 == 0x01){ // der er kun en aktiv blok under bolden
							return 2;
						} else {
							return 0;
						}
					} else {											// vi rammer kun en blok til højre for bolden
						if ( blocks[ ballYArray ][ ballXArray + 1 ] && 0x01 == 0x01 ) { // er denne blok aktiv ?
							return 1;
						} else {
							return 0;
						}
					}
				} else {													// så står der ingen blok til højre for bolden
					if ( (( ballY + 1 ) >> 1 ) != ballYArray ) {	// så står der en blok under bolden
						if ( ( blocks[ballYArray + 1 ][ ballXArray ] && 0x01 == 0x01 )){ // er der noget på denne position
							return 2;										
						} else {
							return 0;
						}
					} else {												// vi rammer ingen blokke til højre eller under bolden											
						return 0;
					}
				}
			} else {														// xV er negativ, yV positiv
					/*	gotoxy(175,debug);
						printf(" y + x -");
						debug++;*/
				if ( (( ballXOffset - 1 ) >> 3 ) != ballXArray ) {		// så står der en blok til venstre for bolden
					if ( (( ballY + 1 ) >> 1 ) != ballYArray ) {		// så står der OGSÅ en blok under bolden
						if ( ( blocks[ ballYArray ][ ballXArray - 1 ] && 0x01 == 0x01 )
							&& ( blocks[ ballYArray + 1 ][ ballXArray ] && 0x01 == 0x01  ) ){	// er der noget på disse positioner
							return 8;										// vend 180 grader
						} else if ( blocks[ ballYArray ][ ballXArray - 1 ] && 0x01 == 0x01 ) {// der er kun en aktiv blok til venstre for blokken
							return 1;
						} else if ( blocks[ ballYArray + 1 ][ ballXArray ] && 0x01 == 0x01){ // der er kun en aktiv blok under bolden
							return 2;
						} else {
							return 0;
						}
					} else {											// vi rammer kun en blok til venstre for bolden
						if ( blocks[ ballYArray ][ ballXArray - 1 ] && 0x01 == 0x01 ) { // er denne blok aktiv ?
							return 1;
						} else {
							return 0;
						}
					}
				} else {													// så står der ingen blok til højre for bolden
					if ( (( ballY + 1 ) >> 1 ) != ballYArray ) {			// så står der en blok under bolden
						if ( ( blocks[ ballXArray ][ ballYArray + 1 ] && 0x01 == 0x01  )){ // er der noget på denne position
							gotoxy(175,debug);
							printf("HIT U %d %d %d %d nH", ballXArray, ballYArray + 1, ballX , ballY);
							debug++;
							return 2;										
						} else {
							return 0;
						}
					} else {												// vi rammer ingen blokke til højre eller under bolden											
						return 0;
					}
				}
			}
			
		} else {															// yV er negativ
			if ( (*ball).xV > 0 ) {									// xV er positiv
					/*	gotoxy(175,debug);
						printf(" y - x +");
						debug++;*/
				if ( (( ballXOffset + 1 ) >> 3 ) != ballXArray ) {		// så står der en blok til højre for bolden
					if ( (( ballY - 1 ) >> 1 ) != ballYArray ) {	// så står der OGSÅ en blok over bolden
						if ( ( blocks[ ballYArray ][ ballXArray + 1 ] && 0x01 == 0x01 )
							&& ( blocks[ ballYArray - 1 ][ ballXArray ] && 0x01 == 0x01  ) ){	// er der noget på disse positioner
							return 8;										// vend 180 grader
						} else if ( blocks[ ballYArray ][ ballXArray + 1 ] && 0x01 == 0x01 ) {// der er kun en aktiv blok til højre for blokken
							return 1;
						} else if ( blocks[ ballYArray - 1 ][ ballXArray ] && 0x01 == 0x01){ // der er kun en aktiv blok over bolden
							return 2;
						} else {
						/*	gotoxy(175,debug);
							printf("H O ik aktiv");
							debug++;*/
							return 0;
						}
					} else {											// vi rammer kun en blok til højre for bolden
						if ( blocks[ ballYArray ][ ballXArray + 1 ] && 0x01 == 0x01 ) { // er denne blok aktiv ?
							return 1;
						} else {
						/*	gotoxy(175,debug);
							printf("H blok ik aktiv");
							debug++;*/
							return 0;
						}
					}
				} else {													// så står der ingen blok til højre for bolden
					if ( (( ballY - 1 ) >> 1 ) != ballYArray ) {			// så står der en blok over bolden
						if ( ( blocks[ballYArray - 1 ][ ballXArray ] && 0x01 == 0x01  )){ // er der noget på denne position
							gotoxy(175,debug);
							printf("HIT! O %d %d %d %d nH", ballXArray, ballYArray - 1, ballX , ballY);
							debug++;
							return 2;										
						} else {
						/*	gotoxy(175,debug);
							printf("O ik aktiv");
							debug++;*/
							return 0;
						}
					} else {												// vi rammer ingen blokke til højre eller under bolden											
					/*	gotoxy(175,debug);
						printf("ingen blok");
						debug++;*/
						return 0;
					}
				}
				
				
			} else {											// yV og xV er negative
					/*	gotoxy(175,debug);
						printf(" y - x -");
						debug++;*/
				if ( (( ballXOffset - 1 ) >> 3 ) != ballXArray ) {		// så står der en blok til venstre for bolden
					if ( ((ballY - 1 ) >> 1 ) != ballYArray ) {			// så står der OGSÅ en blok over bolden
						if ( (( blocks[ ballYArray ][ ballXArray - 1 ] && 0x01 ) == 0x01 )
							&& (( blocks[ ballYArray - 1 ][ ballXArray ] && 0x01 ) == 0x01  ) ){	// er der noget på disse positioner
							return 8;										// vend 180 grader
						} else if (( blocks[ ballYArray ][ ballXArray - 1 ] && 0x01 ) == 0x01 ) {	// der er kun en aktiv blok til venstre for bolden
							return 1;
						} else if (( blocks[ ballYArray - 1 ][ ballXArray ] && 0x01 ) == 0x01){ 	// der er kun en aktiv blok over bolden
							return 2;
						} else {
							return 0;
						}
					} else {											// vi rammer kun en blok til venstre for bolden
						if (( blocks[ ballYArray ][ ballXArray - 1 ] && 0x01 ) == 0x01 ) { // er denne blok aktiv ?
								gotoxy(40, 62);
								printf("%d",blocks[ ballYArray ][ ballXArray - 1 ] );
							return 222;		// 1
						} else {
							return 0;
						}
					}
				} else {													// så står der ingen blok til venstre for bolden
					if ( (( ballY - 1 ) >> 1 ) != ballYArray ) {	// så står der en blok over bolden
						if ( ( blocks[ ballYArray - 1 ][ ballXArray ] && 0x01 == 0x01  )){ // er der noget på denne position
							gotoxy(175,debug);
							printf("HIT O %d %d %d %d nV", ballXArray, ballYArray - 1, ballX, ballY);
							debug++;
							return 2;										
						} else {
							return 0;
						}
					} else {												// vi rammer ingen blokke til venstre eller over bolden											
						return 0;
					}
				}
			}
		}
	} else {
		return 0;
	}
}
