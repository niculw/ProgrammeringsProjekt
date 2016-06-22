//#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "defines.h"
#include "life.h"
#include "game.h"

#define GAMEOVER_X 25

void printLife( struct controlData * ctrlData ) {			
	char i;
	color(1,0);
	for ( i = 0; i < (*ctrlData).playerLife ; i++){
		gotoxy( RESOLUTION_X + 3, i * 5 + 5 );
		printf(" #   # ");
		gotoxy( RESOLUTION_X + 3, i * 5 + 6 );
		printf("### ###");
		gotoxy( RESOLUTION_X + 3, i * 5 + 7 );
		printf(" ##### ");
		gotoxy( RESOLUTION_X + 3, i * 5 + 8 );
		printf("  ###  ");
		gotoxy( RESOLUTION_X + 3, i * 5 + 9 );
		printf("   #   ");
	} 
}

void addLife( struct controlData * ctrlData ) {
	if ( 5 > (*ctrlData).playerLife ) {
		if ((*ctrlData).playerLife > 2)
			color(5,0);
		else color(1,0);
		gotoxy( RESOLUTION_X + 3, (*ctrlData).playerLife * 5 + 5 );
		printf(" #   # ");
		gotoxy( RESOLUTION_X + 3, (*ctrlData).playerLife * 5 + 6 );
		printf("### ###");
		gotoxy( RESOLUTION_X + 3, (*ctrlData).playerLife * 5 + 7 );
		printf(" ##### ");
		gotoxy( RESOLUTION_X + 3, (*ctrlData).playerLife * 5 + 8 );
		printf("  ###  ");
		gotoxy( RESOLUTION_X + 3, (*ctrlData).playerLife * 5 + 9 );
		printf("   #   ");
		(*ctrlData).playerLife++;
	}
}

void removeLife( struct controlData * ctrlData ){
	unsigned char i;
	color(11,0);
	(*ctrlData).playerLife--;
	for (i = 0; i < 5; i++){
		gotoxy( RESOLUTION_X + 3, 5 + (*ctrlData).playerLife * 5 + i );
		printf("       ");
	}
	if ((*ctrlData).playerLife <= 0){
		gotoxy(GAMEOVER_X,10);
		printf("###############################################################################################################################");
		gotoxy(GAMEOVER_X,11);
		printf("###############################################################################################################################");
		gotoxy(GAMEOVER_X,12);
		printf("##                                                                                                                           ##");
		gotoxy(GAMEOVER_X,13);
		printf("##                                          ____                                                                             ##");
		gotoxy(GAMEOVER_X,14);
		printf("##                                         / ___| __ _ _ __ ___   ___    _____   _____ _ __                                  ##");
		gotoxy(GAMEOVER_X,15);
		printf("##                                         | |  _ / _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__|                                ##");
		gotoxy(GAMEOVER_X,16);
		printf("##                                         | |_| | (_| | | | | | |  __/ | (_) \ V /  __/ |                                   ##");
		gotoxy(GAMEOVER_X,17);
		printf("##                                          \\____|\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|                                   ##");
		gotoxy(GAMEOVER_X,18);
		printf("##                                                                                                                           ##");
		gotoxy(GAMEOVER_X,19);
		printf("##                                                      Du fik %5d Point                                                   ##",(*ctrlData).point);
		gotoxy(GAMEOVER_X,20);
		printf("##                                                  Press SW2 to restart to level 1                                          ##");
		gotoxy(GAMEOVER_X,21);
		printf("###############################################################################################################################");
		gotoxy(GAMEOVER_X,22);
		printf("###############################################################################################################################");
	}
}