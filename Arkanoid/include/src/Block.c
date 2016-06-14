//#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "Block.h"

void initBlocks(struct block *b, int x1, int y1) {
	int farve = 0, n = 7;
    
	int i, x = 32, num = 0, x_temp = x1;

	while (num < NUM_BLOCKS) {
		while (x1 < 160 && num < NUM_BLOCKS) {
			int x2 = x1 + n; 
			b[num].xleft = x1;
  	 		b[num].ytop = y1;
   			b[num].xright = x2;
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
		
			x1 += n;
			num++;
			
		} 
		y1 += 2;
		x1 = x_temp;
	}
	reverse('p');
}
