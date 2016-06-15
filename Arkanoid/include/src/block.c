 //#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"

#define NUM_BLOCKS 50

struct block {
	int xleft, ytop, xright, ybot;
};


void printBlocks(struct block b[NUM_BLOCKS], int x1, int y1, int color) {		   
	int i, x = 196, y = 179, num = 0, x_temp = x1;

	int a[4] = { 218, 192, 217, 191 };

	while (num != NUM_BLOCKS) {
		int y2 = y1 + 1;
		while (x1 < 160) {

			int x2 = x1 + 5;

			for (i = y1; i < y2; i++) {
				gotoxy(x1, i);
				printf("%c", y);
				gotoxy(x2, i);
				printf("%c", y);
			}
			gotoxy(x1 + 1, y2);
			for (i = x1 + 1; i < x2; i++) {
				printf("%c", x);
			}
			gotoxy(x1 + 1, y1);
			for (i = x1 + 1; i < x2; i++) {
				printf("%c", x);
			}

			gotoxy(x1, y1);
			printf("%c", a[0]);
			gotoxy(x1, y2);
			printf("%c", a[1]);
			gotoxy(x2, y2);
			printf("%c", a[2]);
			gotoxy(x2, y1);
			printf("%c", a[3]);

            b[num].xleft = x1;
            b[num].ytop = y1;
            b[num].xright = x2;
            b[num].ybot = y2;
            
			x1 += 7;
			
			num++;

		}
		y1 += 3;
		x1 = x_temp;
	}						   
}
/*
void main() {
	printBlocks(&b, 2, 2, 4);
}		 */
