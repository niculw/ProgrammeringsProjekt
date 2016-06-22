#include <eZ8.h>             // special encore constants, macros and flash routines
#include "charset.h"
#include "game.h"

void LEDinit(){
	////////////////////////////////////////////////// LED config
	// 1 for input 0 for output
	PEDD = 0x00;
	PGDD = 0x00;
}

void initVideoBuffer( struct controlData * ctrlData ){
	char i,j;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 5; j++){
			(*ctrlData).videoBuffer[i][j] = character_data[ 16 ][ j ];
		}
	}
}

void LEDsetString(struct controlData * ctrlData ){
	char i,j;
 	int n = (*ctrlData).point;
	for ( i = 3; i >= 0; i--){
		for ( j = 0; j < 5; j++){
			(*ctrlData).videoBuffer[i][j] = character_data[ (n % 10) + 16 ][ j ];
		}
		n /= 10;
	}
}

void LEDupdate( struct controlData * ctrlData ){
	static char karakter = 0, Coll = 4, count = 0;
	static char col = 0xFE;									///// 1111 1110
	PEOUT &= col;									///// tænder for den kolonne vi vil vise
	PGOUT |= (*ctrlData).videoBuffer[ karakter ][ Coll ];	///// tænder for de dioder der skal vises på den kolonne
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
		if ( Coll > 0){
			col |= 0x1F;
			switch ( Coll ) {	
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
			} Coll--;
		} else {
			col = 0xFE;
			Coll = 4;
		}
	}
}
