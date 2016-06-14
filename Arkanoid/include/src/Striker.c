#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "Striker.h"
#include "defines.h"

void initStriker(){
	int i;
	color(2,0);
	for ( i = 0; i < STRIKER_WIDTH ; i++){
		gotoxy( 80 + i, RESOLUTION_Y - 1);
		printf("%c", 178);					//// draw new stiker
	}
}

void drawStriker( int position ){
	static int oldStrikerPos = 80;
	color(2,0);
	//int i;
	if ( oldStrikerPos < position) {		//// kører vi til højre
	//	gotoxy(oldStrikerPos, 60);
		gotoxy(position - 1 , RESOLUTION_Y - 1);
		printf("%c",32);					//// remove old stiker
		gotoxy(position + STRIKER_WIDTH - 1 , RESOLUTION_Y - 1);
		printf("%c", 178);					//// draw new stiker
	} else if ( oldStrikerPos > position ) {		//// ellers kører vi til venstre
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
