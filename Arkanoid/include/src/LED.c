#include <eZ8.h>             // special encore constants, macros and flash routines
#include "charset.h"

//int timeForRefresh = 0;
/*
#pragma interrupt
void refreshDisplay() {
	timeForRefresh = 1;
}
*/

void LEDinit(){
	/////////////////////////////////////////////////// LED config
	PEDD = 0x00;                                     // 1 for input 0 for output
	PGDD = 0x00;
	/////////////////////////////////////////////////// interrupt setup
	DI();							               	 // disable interupt
//	SET_VECTOR(TIMER0, refreshDisplay);
//	IRQ0ENH &= 0x00;		// low prioitet
//	IRQ0ENL |= 0x20;		// low prioitet
	//////////////////////////////////////////////////// timer 0 config
//	T0RH = 0x24;			// set reload high value 
//	T0RL = 0x00;			// set reload low value
//	T0H = 0x00;				// timer byte high = 00000000
//	T0L = 0x01;				// timer byte low = 00000001
//	T0CTL = 0x81;			// 1000 0001 // enable and continious mode
	EI();
}


void initVideoBuffer( char videoBuffer[5][6] ){
	char i,j;
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			videoBuffer[i][j] = character_data[ 48 - 32 ][ j ];
		}
		videoBuffer[i][5] = 0;
	}
}

void LEDsetString(char videoBuffer[5][6],  unsigned int points ){
	int i,j;
	for ( i = 0; i < 5; i++){
		for ( j = 0; j < 5; j++){
			videoBuffer[i][j] = character_data[ (points % 10) + 16 ][ j ];
		}
		points /= 10;
		videoBuffer[i][5] = 0;
	}
}

void mellemled( char string[], int n) {
/*	int i,j = n;
	static int coun = 0, ch = 0, inde = 0;
	char str[] = "     ";
	coun++;
	if (coun == 500) {
		coun = 0;
		if (inde < 6){			// tid til at skifte videobuffer?
		 	inde++;
		} else {				// hvis ja
			inde = 0;
			if (n > ch) {
				for ( i = 0; i < 5; i++){
					if ( ch + i < n ){
						str[i] += string[ch+i] - 32;
					} else {
						str[i] += string[ ch + i -n ] - 32;
					}
				}
				 if ( ch == n-1)
					 ch = 0;
				 else {
					 ch++;
				 }
			}
			LEDsetString( str );	/// skriv til videobuffer
		}
	}*/
}

void LEDupdate( char videoBuffer[5][6] ){
	int i,j;
	static int karakter = 0, cl = 4, count = 0, index = 0;
	static char col = 0xFE;									///// 1111 1110
	//	printf("TFR: %d \n",timeForRefresh);
/*	count++;
	if (count == 500) {
		count = 0;
		if (index < 6){
		 //	index++;
		} else {
			index = 0;
	//		for (i = 0; i < 4; i++){
	//			for (j = 0; j < 6; j++){
	//				videoBuffer[i][j] = videoBuffer[i+1][j];
	//			}
	//		}
	//		for (i = 0; i < 5; i++){
	//			videoBuffer[4][i] = character_data['a' - 32][i];
	//		}
		}
	}*/
//	if ( 1 == timeForRefresh ) {
		PEOUT &= col;									///// tænder for den kolonne vi vil vise
		PGOUT |= videoBuffer[ karakter ][ cl + index ];			///// tænder for de dioder der skal vises på den kolonne
		switch (karakter) {								///// vælger hvilket display
			case 0 :
				PEOUT |= 0x80;							///// clock 1 high
				PEOUT &= 0x7F;							///// clock 1 low
				break;
			case 1 :
				PGOUT |= 0x80;							///// clock 2 high
				PGOUT &= 0x7F;							///// clock 2 low
				break;
			case 2 :
				PEOUT |= 0x20;							///// clock 3 high
				PEOUT &= 0xDF;							///// clock 3 low
				break;
			case 3 :
				PEOUT |= 0x40;							///// clock 4 high
				PEOUT &= 0xBF;							///// clock 4 low
				break;
		}
		PEOUT |= 0x1F;									///// slukker alle colonner, 
		PGOUT &= 0x80;									///// slukker alle row data

				/////////// Next step
		if (karakter < 4){
				karakter++;
		} else { 
			karakter = 0;
			if ( cl > 0){
				col |= 0x1F;
				switch ( cl ) {	
					case 4 : col &= 0xFD;
						break;
					case 3 : col &= 0xFB;
						break;
					case 2 : col &= 0xF7;
						break;
					case 1 : col &= 0xEF;
						break;
					case 0 : col &= 0xFE;
						break;
				} cl--;
			} else {
				col = 0xFE;
				cl = 4;
			}
		}
//		timeForRefresh = 0;
//	} 
}
