//#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "Block.h"


void setLife(struct block *b, int x1, int y1, int collision){

}

void setLevelBlocks(struct block *b, int x1, int y1, int level, int num){
	if(level == 1){
		 if((b[num].xleft < 20 || b[num].xleft > 140) && b[num].ytop < 22){
			b[num].life = 10;
		} else if (b[num].ytop == y1){
			b[num].life = 10;
		} else if(b[num].ytop == y1 + 2){
			b[num].life = 3;
		} else if (b[num].ytop == y1 + (2 * 2)){
			b[num].life = 2;
		} else if (b[num].ytop == y1 + (3 * 2)){
			b[num].life = 1;
		}  else {
			b[num].life = 1;
		}
		
 	}
}

void setColor(struct block *b, int num){
	switch (b[num].life){
		case 0 :
			fgcolor(0);
			break;
		case 1 :
			fgcolor(2);
			break;
		case 2 :
			fgcolor(11);
			break;
		case 3 :
			fgcolor(1);
			break;
		case 10 :
			fgcolor(4);
			break;
	}
}



void printBlocks(struct block *b, int x1, int y1, int n) {
	int i, x = 32, num = 0, x_temp = x1, y_temp = y1;
	while (num < NUM_BLOCKS) {
		while (x1 < 160 && num < NUM_BLOCKS) {
			int x2 = x1 + n; 
			b[num].xleft = x1;
  	 		b[num].ytop = y1;
   			b[num].xright = x2;  
 		    setLevelBlocks(b, x1, y_temp, 1, num);
			setColor(b, num);
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


void initBlocks(struct block *b, int x1, int y1, int level, int length){
	printBlocks(b, x1, y1, length);
}
