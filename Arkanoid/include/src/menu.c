#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "menu.h"
#include "ansi.h"

#define XPOS 35
#define YPOS 10

void initMenu(){
	color(7,0);
	gotoxy( XPOS, YPOS );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 1 );
	printf("############################################################################################");	gotoxy( XPOS, YPOS + 2 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 3 );
	printf("###            _____ ______   ____  ____  ______       ____   ____  ___ ___    ___       ###"); gotoxy( XPOS, YPOS + 4 );
	printf("###            / ___/|      T /    T|    \|      T     /    T /    T|   T   T  /  _]     ###"); gotoxy( XPOS, YPOS + 5 );
	printf("###  |#  #|   (   \_ |      |Y  o  ||  D  )      |    Y   __jY  o  || _   _ | /  [_      ###"); gotoxy( XPOS, YPOS + 6 );
	printf("###  | ## |    \__  Tl_j  l_j|     ||    /l_j  l_j    |  T  ||     ||  \_/  |Y    _]     ###"); gotoxy( XPOS, YPOS + 7 );
	printf("###  | ## |    /  \ |  |  |  |  _  ||    \  |  |      |  l_ ||  _  ||   |   ||   [_      ###"); gotoxy( XPOS, YPOS + 8 );
	printf("###  |#  #|    \    |  |  |  |  |  ||  .  Y |  |      |     ||  |  ||   |   ||     T     ###"); gotoxy( XPOS, YPOS + 9 );
	printf("###             \___j  l__j  l__j__jl__j\_j l__j      l___,_jl__j__jl___j___jl_____j     ###"); gotoxy( XPOS, YPOS + 10 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 11 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 12 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 13 );
	printf("###  |    |                                                                              ###"); gotoxy( XPOS, YPOS + 14 );
	printf("###  |    |                                                                              ###"); gotoxy( XPOS, YPOS + 15 );
	printf("###  |    |                                                                              ###"); gotoxy( XPOS, YPOS + 16 );
	printf("###  |    |                                                                              ###"); gotoxy( XPOS, YPOS + 17 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 18 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 19 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 20 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 21 );
	printf("###  |    |                                                                              ###"); gotoxy( XPOS, YPOS + 22 );
	printf("###  |    |                                                                              ###"); gotoxy( XPOS, YPOS + 23 );
	printf("###  |    |                                                                              ###"); gotoxy( XPOS, YPOS + 24 );
	printf("###  |    |                                                                              ###"); gotoxy( XPOS, YPOS + 25 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 26 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 27 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 28 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 29 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 30 );
	printf("###                                                                                      ###"); gotoxy( XPOS, YPOS + 31 );
	printf("############################################################################################"); gotoxy( XPOS, YPOS + 32 );
	printf("############################################################################################"); 
}

void menuSel( short i ){
	static int lastSel = 1;
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
