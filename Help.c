#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "Help.h"

void Help(short button, struct BallPos * ball){
	while(button == 2){
	int	Xtemp = (*ball).xV;
	int	Ytemp = (*ball).yV;
		(*ball).xV = 0;
		(*ball).yV = 0;
		window(30, 20, 90, 40, "Help", 0);
		gotoxy(31, 21);
		printf("controls: \n")
		printf("Move left : PD3 \n");
		printf("Move right : PF7 \n");
		printf("Restart : SW4 / reset \n");
		}
		(*ball).xV = Xtemp;
		(*ball).yV = Ytemp;
	}
