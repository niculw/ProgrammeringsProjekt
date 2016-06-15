include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "help.h"
#include "ansi.h"

#define XPOS 35
#define YPOS 10

void initHelp(){
	color(7,0);
	gotoxy( XPOS, YPOS );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 1 );
	printf("############################################################################################");	gotoxy( XPOS, YPOS + 2 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 3 );
	printf("###               ____            _             _                                        ###"); gotoxy( XPOS, YPOS + 4 );
	printf("###              / ___|___  _ __ | |_ _ __ ___ | |___                                    ###"); gotoxy( XPOS, YPOS + 5 );
	printf("###  |#  #|      | |   / _ \| '_ \| __| '__/ _ \| / __|                                  ###"); gotoxy( XPOS, YPOS + 6 );
	printf("###  | ## |      | |__| (_) | | | | |_| | | (_) | \__ \                                  ###"); gotoxy( XPOS, YPOS + 7 );
	printf("###  | ## |       \____\___/|_| |_|\__|_|  \___/|_|___/                                  ###"); gotoxy( XPOS, YPOS + 8 );
	printf("###  |#  #|                                                                              ###"); gotoxy( XPOS, YPOS + 9 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 10 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 11 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 12 );
	printf("###             ____                                                                     ###"); gotoxy( XPOS, YPOS + 13 );
	printf("###  |    |    |  _ \ _____      _____ _ __ _   _ _ __  ___                              ###"); gotoxy( XPOS, YPOS + 14 );
	printf("###  |    |    | |_) / _ \ \ /\ / / _ \ '__| | | | '_ \/ __|                             ###"); gotoxy( XPOS, YPOS + 15 );
	printf("###  |    |    |  __/ (_) \ V  V /  __/ |  | |_| | |_) \__ \                             ###"); gotoxy( XPOS, YPOS + 16 );
	printf("###  |    |    |_|   \___/ \_/\_/ \___|_|   \__,_| .__/|___/                             ###"); gotoxy( XPOS, YPOS + 17 );
	printf("###                                              |_|                                     ###"); gotoxy( XPOS, YPOS + 18 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 19 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 20 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 21 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 22 );
}

void helpSel( short i ){
	static int lastSel = 1;
	////////////////////// Sletter den gamle menu selection
	switch ( lastSel ) {
		case 1 :
			gotoxy(XPOS + 6, YPOS + 5);		
			break;
		case 2 : 
			gotoxy(XPOS + 6, YPOS + 13);	
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
void printHelp(short sel, int knapKonstant){
if (sel == 1){
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 1 );
	printf("                                                                                            ");	gotoxy( XPOS, YPOS + 2 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 3 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 4 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 5 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 6 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 7 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 8 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 9 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 10 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 11 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 12 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 13 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 14 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 15 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 16 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 17 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 18 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 19 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 20 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 21 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 22 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 1 );
	printf("############################################################################################");	gotoxy( XPOS, YPOS + 2 );
	printf("##                                ("Press PF6 to return")                                 ##"); gotoxy( XPOS, YPOS + 3 );
	printf("##    PF7 - move right                                                                    ##"); gotoxy( XPOS, YPOS + 4 );
	printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 5 );
	printf("##    PF6 - start ball                                                                    ##"); gotoxy( XPOS, YPOS + 6 );
	printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 7 );
	printf("##    PD3 - move left                                                                     ##"); gotoxy( XPOS, YPOS + 8 );
	printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 9 );
	printf("##    reset - restart game                                                                ##"); gotoxy( XPOS, YPOS + 10 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 11 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 12 );
}		
else if (sel == 2){
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 1 );
	printf("                                                                                            ");	gotoxy( XPOS, YPOS + 2 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 3 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 4 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 5 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 6 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 7 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 8 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 9 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 10 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 11 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 12 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 13 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 14 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 15 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 16 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 17 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 18 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 19 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 20 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 21 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 22 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 1 );
	printf("############################################################################################");	gotoxy( XPOS, YPOS + 2 );
	printf("##                                Press PF6 to return                                     ##"); gotoxy( XPOS, YPOS + 3 );
	printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 4 );
	printf("##    @ - Extra life                                                                      ##"); gotoxy( XPOS, YPOS + 5 );
	printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 6 );
	printf("##    / - reduces width of striker                                                        ##"); gotoxy( XPOS, YPOS + 7 );
	printf("##                                                              			  ##"); gotoxy( XPOS, YPOS + 8 );
	printf("##    + - increases the width of striker                                                  ##"); gotoxy( XPOS, YPOS + 9 );
	printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 10 );
	printf("##    * - spawns an extra ball                                                            ##"); gotoxy( XPOS, YPOS + 11 );
	printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 12 );
	printf("##    ÷ - removes a life                                                                  ##"); gotoxy( XPOS, YPOS + 13 );
	printf("##                                                                                        ##"); gotoxy( XPOS, YPOS + 14 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 15 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 16 );
}
if (knapkonstant == 2){
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 1 );
	printf("                                                                                            ");	gotoxy( XPOS, YPOS + 2 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 3 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 4 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 5 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 6 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 7 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 8 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 9 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 10 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 11 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 12 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 13 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 14 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 15 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 16 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 17 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 18 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 19 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 20 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 21 );
	printf("                                                                                            "); gotoxy( XPOS, YPOS + 22 );
initMenu();
}
}
	
