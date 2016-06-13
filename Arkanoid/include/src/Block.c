//#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"

#define NUM_BLOCKS 50

struct block {
	int xleft, ytop, xright;
};


void initBlocks(struct block b[NUM_BLOCKS], int x1, int y1, int x2, int num){
    b[num].xleft = x1;
    b[num].ytop = y1;
    b[num].xright = x2;

    }

}

void printBlocks(struct block b[NUM_BLOCKS], int x1, int y1, int color) {
	int i, x = 32, num = 0, x_temp = x1;

	while (num != NUM_BLOCKS) {
		while (x1 < 160) {

			int x2 = x1 + 5;
            
			gotoxy(x1 + 1, y1);
			for (i = x1 + 1; i < x2; i++) {
				printf("%c", x);
			}
            initBlocks(b, x1, y1, x2, num);
			x1 += 7;
			num++;

		}
		y1 += 2;
		x1 = x_temp;
	}
}
