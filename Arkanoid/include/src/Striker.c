#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "Striker.h"

void initStriker(){
	int i;
	for ( i = 0; i < 15; i++){
		gotoxy( 80 + i, 60);
		printf("%c", 177);					//// draw new stiker
	}
}

void drawStriker( int position ){
	static int oldStrikerPos = 0;
	//int i;
	if ( oldStrikerPos < position) {		//// kører vi til højre
	//	gotoxy(oldStrikerPos, 60);
		gotoxy(position - 1 , 60);
		printf("%c",32);					//// remove old stiker
		gotoxy(position +14 , 60);
		printf("%c", 177);					//// draw new stiker
	} else if ( oldStrikerPos > position ) {								//// ellers kører vi til venstre
	//	gotoxy(oldStrikerPos + 14, 60);
		gotoxy(position + 15 , 60);
		printf("%c",32);					//// remove old stiker
		gotoxy(position, 60);
		printf("%c", 177);					//// draw new stiker
	}
	oldStrikerPos = position;
}

void moveStriker(){
	
}
