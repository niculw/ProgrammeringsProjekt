#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

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