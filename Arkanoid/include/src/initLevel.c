#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "game.h"
#include "ansi.h"
#include "defines.h"
#include "initLevel.h"
#include "game.h"
#include "LED.h"

void drawBorder( unsigned char style ){ 
	unsigned char x, y, i;
	unsigned char a[3][2] = {{218, 191} , {201, 187} , {220, 220}}; // border styles
	color(1,0);
	switch (style) {
		case 0 :
			x = 196;     
			y = 179;
			break;
		    // h�jrne top v, top h
		case 1 :
			x = 205;
			y = 186; 
			break;
	    	// h�jrne top v, top h
		case 2 : 
			x = 220;
			y = 219;
			break;
	}
	for (i = 2; i < 61; i++){
		gotoxy( 1, i);
		printf("%c",y);
		gotoxy( RESOLUTION_X, i);
		printf("%c",y);
	}
	gotoxy( 2,1 );
	for (i = 1 + 1; i < RESOLUTION_X; i++){
		printf("%c",x);	
	}
	gotoxy(1, 1);
	printf("%c", a[style][0]);
	gotoxy(RESOLUTION_X, 1);
	printf("%c", a[style][1]);
}

void initLevel( char block[25][22] , struct controlData * ctrlData ){
	unsigned char i,j;
	switch ( (*ctrlData).level ) {
		case 1 :
			for (i = 0; i < 25; i++){
				for (j = 0; j < 22; j++){
					block[i][j] = LEVEL_1[i][j];
				}
			}
			break;
		case 2 :
			for (i = 0; i < 25; i++){
				for (j = 0; j < 22; j++){
					block[i][j] = LEVEL_2[i][j];
				}
			}
			break;
		case 3 :
			for (i = 0; i < 25; i++){
				for (j = 0; j < 22; j++){
					block[i][j] = LEVEL_3[i][j];
				}
			}	
			break;
		case 4 :
			for (i = 0; i < 25; i++){
				for (j = 0; j < 22; j++){
					block[i][j] = LEVEL_4[i][j];
				}
			}	
			break;
	}
}

void printBlocks( char block[25][22], struct controlData * ctrlData ) {
	unsigned char i, j, k, health;
	gotoxy( 2 , 2 );
	for ( i = 0 ; i < 23 ; i++ ){
		for ( j = 0 ; j < 20 ; j++ ){
			if ( block[i + 1][j + 1] & 0x01 == 0x01 ){		// tjek om blokken er aktiv 
				if (( block[i + 1][j + 1] & 0x08 ) == 0x08 ){
					health = '#';
				} else {
					health = ( 175 + (( block[i + 1][j + 1] & 0x06 ) >> 1 ));	// tr�kker liv ud af blok info
					(*ctrlData).blockCount++;		//// normal mode non cheating
				//	(*ctrlData).blockCount = 1;		//// fast LEVEL CHEAT
				}
				color( ( block[i + 1][j + 1] >> 4 ) , 0);		// s�tter farven p� blokken
				gotoxy( 2 + ( j << 3 ) , 2 + (i << 1)  );	// g�r til blok position
				for (k = 0; k < 8; k++){					
					printf("%c", health);							// farver den �verste del af blokken
				}
				gotoxy( 2 + ( j << 3 ) , 2 + (i << 1) + 1 );
				for (k = 0; k < 8; k++){
					printf("%c", health);							//// farver den nederste del af blokken
				}
			}
		}
	}
}

void removeBlockLife( char * block, struct controlData * ctrlData ) {
	char x;
	if ((*block & 0x08 ) != 0x08){								/// er blokken indestructible ?
		if (( *block & 0x06 ) == 0x02 ){							// er det det sidste blok liv der fjernes?
			*block &= 0xF0;									// fjerner det sidste liv og g�r blokken inaktiv
			(*ctrlData).blockCount--;
			(*ctrlData).point += 5;
		} else {													// mere end et blok liv tilbage
			if (( *block & 0x06 ) == 0x04 ){							//
				(*ctrlData).point += 2;
			} else {
				(*ctrlData).point += 1;
			}
			x = ( *block & 0x06 ) >> 1;
			x--;
			x <<= 1;
			*block &= 0xF9;									// 1111 1001
			*block |= x;
		}
		LEDsetString( ctrlData );
		printControlData( ctrlData );
	}
}

void updateBlock( char * block , unsigned char i, unsigned char j, struct controlData * ctrlData ){
	unsigned char health = 175, k;
	if (( *block & 0x08 ) != 0x08 && (( *block & 0x01 ) == 0x01 )){
		removeBlockLife( block, ctrlData );
		if (( *block & 0x06 ) == 0x00 ){
			health = ' ';
		} else {
			health = ( 175 + (( *block & 0x06 ) >> 1 ));	// tr�kker liv ud af blok info
		}
		color( ( *block >> 4 ) , 0);		// s�tter farven p� blokken
		gotoxy( ( j << 3 ) - 6, (i << 1)  );	// g�r til blok position
		for (k = 0; k < 8; k++){					
			printf("%c", health);							// farver den �verste del af blokken
		}
		gotoxy( ( j << 3 ) - 6 , (i << 1) + 1 );
		for (k = 0; k < 8; k++){
			printf("%c", health);							//// farver den nederste del af blokken
		}
	}
}

void clearLevel(  ){
	unsigned char i, j;
	for (i = 2; i < 50; i++){
	gotoxy(2,i);
 		for (j = 2; j < 162; j++){
			printf(" ");
		}
	}
}

////////////////////////////////////////////////////////////////
/// 	IMPORTANT --  LEVEL DESIGN
///  following requiments should be met when designing a new level
///  - first and last lines should be pure 0x00
///  - first and last collum should be pure 0x00
///  otherwise block collision detection would respond unexpectily
///  because it would check outside of the array size
///  BIT MANIPULATION
///  8765 4321
///  bit 8765 er farven
///  bit 4 er indestructible
///  bit 2 og 3 er liv
///  bit 1 er aktiv 
////////////////////////////////////////////////////////////////
/*
rom const unsigned char LEVEL_1[25][22]= {
//		0	1	2	3	  4		5	6	 7		8	9	10	11	  12	13	14	15	  16	17	18	19	  20    21
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 0					
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 5
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 10
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x29,0x00,0x00},		// 
	{0x00,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 15
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 20
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 24
};*/

rom const unsigned char LEVEL_1[25][22]= {
//		0	1	2	3	  4		5	6	 7		8	9	10	11	  12	13	14	15	  16	17	18	19	  20    21
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 0					
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0x15,0x15,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x35,0x25,0x25,0x35,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x53,0x43,0x43,0x43,0x43,0x53,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 5
	{0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x73,0x73,0x00,0x00,0x00,0x00,0x73,0x73,0x33,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x33,0x73,0x75,0x00,0x00,0x00,0x00,0x00,0x00,0x75,0x73,0x33,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x33,0x73,0x73,0x73,0x73,0x00,0x00,0x00,0x00,0x73,0x73,0x73,0x73,0x33,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x33,0x43,0x73,0x43,0x43,0x43,0x43,0x43,0x43,0x43,0x43,0x43,0x43,0x73,0x43,0x33,0x00,0x00,0x00},		// 
	{0x00,0x00,0x43,0x43,0x43,0x43,0x33,0x33,0x33,0x23,0x29,0x29,0x23,0x33,0x33,0x33,0x43,0x43,0x43,0x43,0x00,0x00},		// 10
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 15
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 20
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 24
};



rom const unsigned char LEVEL_2[25][22]= {
	//	0	1	2	3	  4		5	6	 7		8	9	10	11	  12	13	14	15	  16	17	18	19	  20    21
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 0					
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x13,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 5
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x73,0x73,0x73,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x73,0x23,0x23,0x23,0x73,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x73,0x23,0x15,0x23,0x73,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x73,0x25,0x17,0x25,0x73,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x73,0x23,0x15,0x23,0x73,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 10
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x73,0x23,0x23,0x23,0x73,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x73,0x73,0x73,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x13,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 15
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 20
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 24
};

rom const unsigned char LEVEL_3[25][22]= {
//		0	1	2	3	  4		5	6	 7		8	9	10	11	  12	13	14	15	  16	17	18	19
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 0					
	{0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 5
	{0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00},		// 
	{0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00,0x00},		// 10
	{0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00,0x00},		// 
	{0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x63,0x00},		// 
	{0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00,0x00},		// 15
	{0x00,0x43,0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x53,0x00},		// 
	{0x00,0x00,0x43,0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x43,0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x43,0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x43,0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x15,0x00},		// 20
	{0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x00,0x00,0x33,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x73,0x00,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 24
};

rom const unsigned char LEVEL_4[25][22]= {
//		0	1	2	3	  4		5	6	 7		8	9	10	11	  12	13	14	15	  16	17	18	19
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 0					
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 5
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x00,0x23,0x23,0x23,0x00,0x23,0x23,0x23,0x00,0x23,0x23,0x23,0x00,0x23,0x23,0x23,0x00,0x23,0x23,0x00},		// 
	{0x00,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00},		// 
	{0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x23,0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00},		// 
	{0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x23,0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00},		// 10
	{0x00,0x00,0x00,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x23,0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00},		// 
	{0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x23,0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00},		// 
	{0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x23,0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00},		// 
	{0x00,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x00,0x23,0x23,0x00,0x23,0x23,0x00,0x23,0x00,0x23,0x00},		// 
	{0x00,0x23,0x00,0x23,0x23,0x23,0x00,0x23,0x23,0x23,0x00,0x23,0x23,0x00,0x00,0x00,0x23,0x23,0x00,0x23,0x23,0x00},		// 15
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 20
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x00},		// 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},		// 24
};





