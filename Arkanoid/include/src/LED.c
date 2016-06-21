#include <eZ8.h>             // special encore constants, macros and flash routines
#include "charset.h"
#include "game.h"

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

void initVideoBuffer( struct controlData * ctrlData ){
	char i,j;
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			(*ctrlData).videoBuffer[i][j] = character_data[ 48 - 32 ][ j ];
		}
		(*ctrlData).videoBuffer[i][5] = 0;
	}
}

void LEDsetString(struct controlData * ctrlData ){
	int i,j, n = (*ctrlData).point;
	for ( i = 0; i < 5; i++){
		for ( j = 0; j < 5; j++){
			(*ctrlData).videoBuffer[i][j] = character_data[ (n % 10) + 16 ][ j ];
		}
		n /= 10;
		(*ctrlData).videoBuffer[i][5] = 0;
	}
}

void LEDupdate( struct controlData * ctrlData ){
	int i,j;
	static int karakter = 0, cl = 4, count = 0, index = 0;
	static char col = 0xFE;									///// 1111 1110
	PEOUT &= col;									///// tænder for den kolonne vi vil vise
	PGOUT |= (*ctrlData).videoBuffer[ karakter ][ cl + index ];			///// tænder for de dioder der skal vises på den kolonne
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
}
