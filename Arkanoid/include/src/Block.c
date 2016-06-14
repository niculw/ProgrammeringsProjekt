//#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"

#define NUM_BLOCKS 100	  // antal blokke

struct block {
	int xleft, ytop, xright;
};


void initBlocks(struct block b[NUM_BLOCKS], int x1, int y1, int x2, int num){
    b[num].xleft = x1;
    b[num].ytop = y1;
    b[num].xright = x2;
    }

void printBlocks(int x1, int y1) {
	int farve = 0, n = 7;
    struct block b[NUM_BLOCKS];
	int i, x = 32, num = 0, x_temp = x1;

	while (num < NUM_BLOCKS) {
		while (x1 < 160 && num < NUM_BLOCKS) {
			int x2 = x1 + n;
			if(farve < 6){
			farve++; 
			} else if( farve == 6) {
			farve = 1;
			}
		    fgcolor(farve);
            reverse('o');
			gotoxy(x1 + 1, y1);
			for (i = x1; i <= x2; i++) {
				printf("%c", x);
			}
          	initBlocks(b, x1, y1, x2, num);		   // gemmer koordinat i array
			x1 += n;
			num++;

		}
		y1 += 2;
		x1 = x_temp;
	}
	reverse('p');
//	printf("(x1, y1, x2) %d, %d, %d", b[99].xleft, b[99].ytop, b[99].xright);			    // test print af vilkårlig bloks koordinat
}
