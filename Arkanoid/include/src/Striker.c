//#include <eZ8.h>             // special encore constants, macros and flash routines
//#include <sio.h>             // special encore serial i/o routines
#include <stdio.h>
#include "ansi.h"
#include "Striker.h"

#define RESOLUTION_X 171
#define RESOLUTION_Y 61
#define STRIKER_WIDTH 15		// skal kunne deles med 5

void initStriker(){
	int i;
	color(4,0);
	for ( i = 0; i < STRIKER_WIDTH ; i++){
		gotoxy( 80 + i, RESOLUTION_Y - 1);
		printf("%c", 178);					//// draw new stiker
	}
}

void drawStriker( int position ){
	static int oldStrikerPos = 0;
	color(4,0);
	//int i;
	if ( oldStrikerPos < position) {		//// kører vi til højre
	//	gotoxy(oldStrikerPos, 60);
		gotoxy(position - 1 , RESOLUTION_Y - 1);
		printf("%c",32);					//// remove old stiker
		gotoxy(position + STRIKER_WIDTH - 1 , RESOLUTION_Y - 1);
		printf("%c", 178);					//// draw new stiker
	} else if ( oldStrikerPos > position ) {								//// ellers kører vi til venstre
	//	gotoxy(oldStrikerPos + 14, 60);
		gotoxy(position + 15 , RESOLUTION_Y - 1);
		printf("%c",32);					//// remove old stiker
		gotoxy(position, RESOLUTION_Y - 1);
		printf("%c", 178);					//// draw new stiker
	}
	oldStrikerPos = position;
}

void moveStriker(){
	
}
