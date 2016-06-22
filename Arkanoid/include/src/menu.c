#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "menu.h"
#include "ansi.h"
#include "game.h"

#define XPOS 35
#define YPOS 13
#define WIN 17

void initMenu(){
	color(5,0);
	gotoxy(XPOS - 15, 1);
	printf("         .8.          8 888888888o.   8 8888     ,88'          .8.          b.             8     ,o888888o.      8 8888 8 888888888o.      ");gotoxy(XPOS - 15, 1);
	printf("        .888.         8 8888    `88.  8 8888    ,88'          .888.         888o.          8  . 8888     `88.    8 8888 8 8888    `^888.   ");gotoxy(XPOS - 15, 2);
	printf("       :88888.        8 8888     `88  8 8888   ,88'          :88888.        Y88888o.       8 ,8 8888       `8b   8 8888 8 8888        `88. ");gotoxy(XPOS - 15, 3);
	printf("      . `88888.       8 8888     ,88  8 8888  ,88'          . `88888.       .`Y888888o.    8 88 8888        `8b  8 8888 8 8888         `88 ");gotoxy(XPOS - 15, 4);
	printf("     .8. `88888.      8 8888.   ,88'  8 8888 ,88'          .8. `88888.      8o. `Y888888o. 8 88 8888         88  8 8888 8 8888          88 ");gotoxy(XPOS - 15, 5);
	printf("    .8`8. `88888.     8 888888888P'   8 8888 88'          .8`8. `88888.     8`Y8o. `Y88888o8 88 8888         88  8 8888 8 8888          88 ");gotoxy(XPOS - 15, 6);
	printf("   .8' `8. `88888.    8 8888`8b       8 888888<          .8' `8. `88888.    8   `Y8o. `Y8888 88 8888        ,8P  8 8888 8 8888         ,88 ");gotoxy(XPOS - 15, 7);
	printf("  .8'   `8. `88888.   8 8888 `8b.     8 8888 `Y8.       .8'   `8. `88888.   8      `Y8o. `Y8 `8 8888       ,8P   8 8888 8 8888        ,88' ");gotoxy(XPOS - 15, 8);
	printf(" .888888888. `88888.  8 8888   `8b.   8 8888   `Y8.    .888888888. `88888.  8         `Y8o.`  ` 8888     ,88'    8 8888 8 8888    ,o88P'   ");gotoxy(XPOS - 15, 9);
	printf(".8'       `8. `88888. 8 8888     `88. 8 8888     `Y8. .8'       `8. `88888. 8            `Yo     `8888888P'      8 8888 8 888888888P'      ");gotoxy(XPOS +25, 11);
	printf("By Anders Struck, Jakobo Roel and Nicolai Weis Hansen");
	color(7,0);
	gotoxy( XPOS, YPOS );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 1 );
	printf("############################################################################################");	gotoxy( XPOS, YPOS + 2 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 3 );
	printf("###             _____ ______   ____  ____  ______       ____   ____  ___ ___    ___      ###"); gotoxy( XPOS, YPOS + 4 );
	printf("###            / ___/|      T /    T|    \\|      T     /    T /    T|   T   T  /  _]     ###"); gotoxy( XPOS, YPOS + 5 );
	printf("###  |    |   (   \\_ |      |Y  o  ||  D  )      |    Y   __jY  o  || _   _ | /  [_      ###"); gotoxy( XPOS, YPOS + 6 );
	printf("###  |    |    \\__  Tl_j  l_j|     ||    /l_j  l_j    |  T  ||     ||  \\_/  |Y    _]     ###"); gotoxy( XPOS, YPOS + 7 );
	printf("###  |    |    /  \\ |  |  |  |  _  ||    \\  |  |      |  l_ ||  _  ||   |   ||   [_      ###"); gotoxy( XPOS, YPOS + 8 );
	printf("###  |    |    \\    |  |  |  |  |  ||  .  Y |  |      |     ||  |  ||   |   ||     T     ###"); gotoxy( XPOS, YPOS + 9 );
	printf("###             \\___j  l__j  l__j__jl__j\\_j l__j      l___,_jl__j__jl___j___jl_____j     ###"); gotoxy( XPOS, YPOS + 10 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 11 );
	printf("###              __ __  ____   ____  __ __  _____   __   ___   ____     ___  _____       ###"); gotoxy( XPOS, YPOS + 12 );
	printf("###             |  T  Tl    j /    T|  T  T/ ___/  /  ] /   \\ |    \\   /  _]/ ___/       ###"); gotoxy( XPOS, YPOS + 13 );
	printf("###  |    |     |  l  | |  T Y   __j|  l  (   \\_  /  / Y     Y|  D  ) /  [_(   \\_        ###"); gotoxy( XPOS, YPOS + 14 );
	printf("###  |    |     |  _  | |  | |  T  ||  _  |\\__  T/  /  |  O  ||    / Y    _]\\__  T       ###"); gotoxy( XPOS, YPOS + 15 );
	printf("###  |    |     |  |  | |  | |  l_ ||  |  |/  \\ /   \\_ |     ||    \\ |   [_ /  \\ |       ###"); gotoxy( XPOS, YPOS + 16 );
	printf("###  |    |     |  |  | j  l |     ||  |  |\\    \\     |l     !|  .  Y|     T\\    |       ###"); gotoxy( XPOS, YPOS + 17 );
	printf("###             l__j__j|____jl___,_jl__j__j \\___j\\____j \\___/ l__j\\_jl_____j \\___j       ###"); gotoxy( XPOS, YPOS + 18 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 19 );
	printf("###              __ __    ___  _      ____                                               ###"); gotoxy( XPOS, YPOS + 20 );
	printf("###             |  T  T  /  _]| T    |    \\                                              ###"); gotoxy( XPOS, YPOS + 21 );
	printf("###  |    |     |  l  | /  [_ | |    |  o  )                                             ###"); gotoxy( XPOS, YPOS + 22 );
	printf("###  |    |     |  _  |Y    _]| l___ |   _/                                              ###"); gotoxy( XPOS, YPOS + 23 );
	printf("###  |    |     |  |  ||   [_ |     T|  |                                                ###"); gotoxy( XPOS, YPOS + 24 );
	printf("###  |    |     |  |  ||     T|     ||  |                                                ###"); gotoxy( XPOS, YPOS + 25 );
	printf("###             l__j__jl_____jl_____jl__j                                                ###"); gotoxy( XPOS, YPOS + 26 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 27 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 28 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 29 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 30 );
}

void menuSel( char i ){
	static char lastSel = 1;
	////////////////////// Sletter den gamle menu selection
	switch ( lastSel ) {
		case 1 :
			gotoxy(XPOS + 6, YPOS + 5);		
			break;
		case 2 : 
			gotoxy(XPOS + 6, YPOS + 13);	
			break;
		case 3 : 
			gotoxy(XPOS + 6, YPOS + 21);	
			break;
	}
	printf("    \n");
	goRight( XPOS + 5 );
	printf("    \n");
	goRight( XPOS + 5 );
	printf("    \n");
	goRight( XPOS + 5 );
	printf("    \n");
	goRight( XPOS + 5 );
	///////////////////// sætter kryds i det menu-punkt man vælger.
	switch ( i ) {
		case 1 :
			gotoxy(XPOS + 6, YPOS + 5);		
			break;
		case 2 : 
			gotoxy(XPOS + 6, YPOS + 13);	
			break;
		case 3 : 
			gotoxy(XPOS + 6, YPOS + 21);	
			break;
	}
	printf("#  #\n");
	goRight( XPOS + 5 );
	printf(" ## \n");
	goRight( XPOS + 5 );
	printf(" ## \n");
	goRight( XPOS + 5 );
	printf("#  #\n");
	goRight( XPOS + 5 );
	lastSel = i;
}

void printWin( struct controlData * ctrlData ){
		color( 5,0 );
		gotoxy(WIN,10);
		printf("###############################################################################################################################");gotoxy(WIN,11);
		printf("###############################################################################################################################");gotoxy(WIN,12);
		printf("##                                                                                                                           ##");gotoxy(WIN,13);
		printf("##                          ____                            _         _       _   _                 _                        ##");gotoxy(WIN,14);
		printf("##                         / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___| |                       ##");gotoxy(WIN,15);
		printf("##                        | |   / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __| |                       ##");gotoxy(WIN,16);
		printf("##                        | |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \_|                       ##");gotoxy(WIN,17);
		printf("##                         \____\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___(_)                       ##");gotoxy(WIN,18);
		printf("##                                           |___/                                                                           ##");gotoxy(WIN,19);
		printf("##                                                                                                                           ##");gotoxy(WIN,20);
		printf("##                                                      Du fik %5d Point                                                   ##",(*ctrlData).point);gotoxy(WIN,21);
		printf("##                                                                                                                           ##");gotoxy(WIN,22);
		printf("##                                                  Press SW2 to go to main Menu                                             ##");gotoxy(WIN,23);
		printf("###############################################################################################################################");gotoxy(WIN,24);
		printf("###############################################################################################################################");
}
