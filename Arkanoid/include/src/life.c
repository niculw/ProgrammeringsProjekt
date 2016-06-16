//#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "defines.h"
#include "life.h"

#define GAMEOVER_X 25

void initLife( struct lives * life ){
	(*life).Lives = 3;
	printLife( life );
}

void printLife( struct lives * life ) {
	static short oldlife = 3;				// vi starter på 3 liv
	char i;
	
	if ( 4 <= (*life).Lives ){
		color(5,0);
	} else {
		color(1,0);
	}
	for ( i = 0; i < (*life).Lives ; i++){
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

void addLife( struct lives * life  ) {
	if ( 5 > (*life).Lives ) {
		(*life).Lives++;
		printLife( life );
	}
}

void removeLife( struct lives * life ){
	color(11,0);
	(*life).Lives--;
	gotoxy( RESOLUTION_X + 3, 4 + (*life).Lives * 5 );
	printf("       ");
	gotoxy( RESOLUTION_X + 3, 4 + (*life).Lives * 5 + 1 );
	printf("       ");
	gotoxy( RESOLUTION_X + 3, 4 + (*life).Lives * 5 + 2 );
	printf("       ");
	gotoxy( RESOLUTION_X + 3, 4 + (*life).Lives * 5 + 3 );
	printf("       ");
	gotoxy( RESOLUTION_X + 3, 4 + (*life).Lives * 5 + 4 );
	printf("       ");

	if ((*life).Lives <= 0){
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
	printf("%d", (*life).Lives);
}