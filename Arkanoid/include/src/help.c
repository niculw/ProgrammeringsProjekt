#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "help.h"
#include "ansi.h"

#define XPOS 35
#define YPOS 13

void initHelp(){
	color(7,0);
	gotoxy( XPOS, YPOS );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 1 );
	printf("############################################################################################");	gotoxy( XPOS, YPOS + 2 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 3 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 4 );
	printf("###                ____            _             _                                       ###"); gotoxy( XPOS, YPOS + 5 );
	printf("###  |    |       / ___|___  _ __ | |_ _ __ ___ | |___                                   ###"); gotoxy( XPOS, YPOS + 6 );
	printf("###  |    |      | |   / _ \\| '_ \\| __| '__/ _ \\| / __|                                  ###"); gotoxy( XPOS, YPOS + 7 );
	printf("###  |    |      | |__| (_) | | | | |_| | | (_) | \\__ \\                                  ###"); gotoxy( XPOS, YPOS + 8 );
	printf("###  |    |       \\____\\___/|_| |_|\\__|_|  \\___/|_|___/                                  ###"); gotoxy( XPOS, YPOS + 9 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 10 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 11 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 12 );
	printf("###               ____  _            _                                                   ###"); gotoxy( XPOS, YPOS + 13 );
	printf("###  |    |      | __ )| | ___   ___| | _____                                            ###"); gotoxy( XPOS, YPOS + 14 );
	printf("###  |    |      |  _ \\| |/ _ \\ / __| |/ / __|                                           ###"); gotoxy( XPOS, YPOS + 15 );
	printf("###  |    |      | |_) | | (_) | (__|   <\\__ \\                                           ###"); gotoxy( XPOS, YPOS + 16 );
	printf("###  |    |      |____/|_|\\___/ \\___|_|\\_\\___/                                           ###"); gotoxy( XPOS, YPOS + 17 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 18 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 19 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 20 );
	printf("###               ____             _                                                     ###"); gotoxy( XPOS, YPOS + 21 );
	printf("###  |    |      | __ )  __ _  ___| | __                                                 ###"); gotoxy( XPOS, YPOS + 22 );
	printf("###  |    |      |  _ \\ / _` |/ __| |/ /                                                 ###"); gotoxy( XPOS, YPOS + 23 );
	printf("###  |    |      | |_) | (_| | (__|   <                                                  ###"); gotoxy( XPOS, YPOS + 24 );
	printf("###  |    |      |____/ \\__,_|\\___|_|\\_\\                                                 ###"); gotoxy( XPOS, YPOS + 25 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 26 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 27 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 28 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 29 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 30 );
}

void printHelp(char sel){
	color(7,0);
	if (sel == 1){
		gotoxy( XPOS, YPOS ); 
		printf("############################################################################################"); gotoxy( XPOS, YPOS + 1 );
		printf("############################################################################################");	gotoxy( XPOS, YPOS + 2 );
		printf("##                                 (Press SW2 to return)                                  ##"); gotoxy( XPOS, YPOS + 3 );
		printf("##    PF7 - move right                                                                    ##"); gotoxy( XPOS, YPOS + 4 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 5 );
		printf("##    PF6 - start ball                                                                    ##"); gotoxy( XPOS, YPOS + 6 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 7 );
		printf("##    PD3 - move left                                                                     ##"); gotoxy( XPOS, YPOS + 8 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 9 );
		printf("##    reset - restart game                                                                ##"); gotoxy( XPOS, YPOS + 10 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 11 );
		printf("############################################################################################"); gotoxy( XPOS, YPOS + 12 );
		printf("############################################################################################"); gotoxy( XPOS, YPOS + 13 );
	} else if (sel == 2){
	gotoxy( XPOS, YPOS ); 
		printf("############################################################################################"); gotoxy( XPOS, YPOS + 1 );
		printf("############################################################################################");	gotoxy( XPOS, YPOS + 2 );
		printf("##                                Press SW2 to return                                     ##"); gotoxy( XPOS, YPOS + 3 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 4 );
		printf("##       Blok type:         Beskrivelse:                                                  ##"); gotoxy( XPOS, YPOS + 5 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 6 );
		printf("##    %c%c%c%c%c%c%c%c    er blokke med et liv                                                    ##", 176,176,176,176,176,176,176,176 ); gotoxy( XPOS, YPOS + 7 );
		printf("##    %c%c%c%c%c%c%c%c                                                                            ##", 176,176,176,176,176,176,176,176 ); gotoxy( XPOS, YPOS + 8 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 9 );
		printf("##    %c%c%c%c%c%c%c%c    er blokke med to liv                                                    ##", 177,177,177,177,177,177,177,177 ); gotoxy( XPOS, YPOS + 10 );
		printf("##    %c%c%c%c%c%c%c%c                                                                            ##", 177,177,177,177,177,177,177,177 ); gotoxy( XPOS, YPOS + 11 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 12 );
		printf("##    %c%c%c%c%c%c%c%c    er blokke med tre liv                                                   ##", 178,178,178,178,178,178,178,178 ); gotoxy( XPOS, YPOS + 13 );
		printf("##    %c%c%c%c%c%c%c%c                                                                            ##", 178,178,178,178,178,178,178,178 ); gotoxy( XPOS, YPOS + 14 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 15 );
		printf("##    %c%c%c%c%c%c%c%c    er blokke som er indestructible                                         ##", '#','#','#','#','#','#','#','#'); gotoxy( XPOS, YPOS + 16 );
		printf("##    %c%c%c%c%c%c%c%c                                                                            ##", '#','#','#','#','#','#','#','#'); gotoxy( XPOS, YPOS + 17 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 18 );
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 19 );   
		printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 20 );
		printf("############################################################################################"); gotoxy( XPOS, YPOS + 21 );
		printf("############################################################################################"); gotoxy( XPOS, YPOS + 22 );
	}
}

	

