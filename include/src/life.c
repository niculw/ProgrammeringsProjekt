//#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "defines.h"
#include "life.h"

#define GAMEOVER_X 25

void initLife( struct lives * L ){
	int i;
	color(1,0);
	(*L).Lives = 3;
	for ( i = 0; i < 3 ; i++){
		gotoxy( RESOLUTION_X + 3, 4 + i * 5 );
		printf(" #   # ");
		gotoxy( RESOLUTION_X + 3, 4 + i * 5 + 1 );
		printf("### ###");
		gotoxy( RESOLUTION_X + 3, 4 + i * 5 + 2 );
		printf(" ##### ");
		gotoxy( RESOLUTION_X + 3, 4 + i * 5 + 3 );
		printf("  ###  ");
		gotoxy( RESOLUTION_X + 3, 4 + i * 5 + 4);
		printf("   #   ");
	}
}

void printLife( struct lives * life ) {
	static short oldlife = 3;				// vi starter på 3 liv
	
	//	(*L).Lives ;
}

void addLife( struct lives * life  ) {
	if ( 5 > (*life).Lives ) {
		(*life).Lives++;
	}
}

void lifeChanger( struct lives * L ){
	color(11,0);
	(*L).Lives--;
	if ((*L).Lives <= 0){
		gotoxy(GAMEOVER_X,10);
		printf("###############################################################################################################################");
		gotoxy(GAMEOVER_X,11);
		printf("###############################################################################################################################");
		gotoxy(GAMEOVER_X,12);
		printf("##                                                                                                                           ##");
		gotoxy(GAMEOVER_X,13);
		printf("##                                            ____                                                                           ##");
		gotoxy(GAMEOVER_X,14);
		printf("##                                           / ___| __ _ _ __ ___   ___    _____   _____ _ __                                ##");
		gotoxy(GAMEOVER_X,15);
		printf("##                                           | |  _ / _` | '_ ` _ \ / _ \  / _ \ \ / / _ \ '__|                              ##");
		gotoxy(GAMEOVER_X,16);
		printf("##                                           | |_| | (_| | | | | | |  __/ | (_) \ V /  __/ |                                 ##");
		gotoxy(GAMEOVER_X,17);
		printf("##                                            \____|\__,_|_| |_| |_|\___|  \___/ \_/ \___|_|                                 ##");
		gotoxy(GAMEOVER_X,18);
		printf("##                                                                                                                           ##");
		gotoxy(GAMEOVER_X,19);
		printf("###############################################################################################################################");
		gotoxy(GAMEOVER_X,20);
		printf("###############################################################################################################################");
	}
	gotoxy(10, 62);
	printf("%d", (*L).Lives);
}