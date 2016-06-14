//#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"#include "life.h"

struct lives{
int Lives;
};


void initLife(struct lives * L){
(*L).Lives = 3;
}

void lifeChanger(struct lives * L ){
	if (collisionDetect == -1){
		(*L).Lives--;
		}
	else if (Extra == 1){
		(*L).Lives++;
	}

	if ((*L).Lives == 0){

	gotoxy(60,40);
		printf("you lose");	   

	}
}

