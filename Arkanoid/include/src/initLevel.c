#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

#include "ansi.h"

#define RESOLUTION_X 171
#define RESOLUTION_Y 61

void drawBorder( int style ){ 
	int x, y;
	int i;
	int a[3][2] = {{218, 191},
			   {201, 187},
			   {220, 220}};
	
	switch (style) {
	case 0 :
		x = 196;     
		y = 179;
		break;
	    // højrne top v, ned v, ned h, top h, overskrift v, overskift h
	case 1 :
		x = 205;
		y = 186; 
		break;
    	// højrne top v, ned v, ned h, top h, overskrift v, overskift h
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

