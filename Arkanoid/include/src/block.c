//#include <stdio.h>
//#include <stdlib.h>
#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "Block.h"


void updateLife(struct block *b, int x1, int y1, int collision){
	int i;
	if (collision == 1){
		for (i = 0; i < NUM_BLOCKS ; i++){
			if (x1 == b[i].xleft && y1 == b[i].ytop){
				b[i].life -= 1;
				setColor(b, i);
				break;
			}
		}
	}
}

void initLevels(struct block *b, int level){
	reverse('o');
	switch (level){
		case 1 :
			drawBlockLines(b, 77, 9, 8, 2, 10, 0);
			drawBlockLines(b, 77, 10, 8, 2, 3, 2);
			drawBlockLines(b, 69, 11, 8, 4, 2, 4);
			drawBlockLines(b, 61, 12, 8, 6, 2, 8);
			drawBlockLines(b, 53, 13, 8, 8, 1, 14);
			drawBlockLines(b, 45, 14, 8, 10, 1, 22);
			drawBlockLines(b, 37, 15, 8, 12, 1, 34);
			drawBlockLines(b, 37, 16, 8, 12, 1, 46);
			break;
		case 2 :
			drawBlockLines(b, 13, 12, 8, 19, 3, 0);
		    drawBlockLines(b, 13, 13, 8, 19, 2, 19);
			drawBlockLines(b, 13, 14, 8, 19, 2, 38);
			drawBlockLines(b, 13, 15, 8, 19, 1, 57);
			break;
		case 3 :
		 	drawBlockLines(b, 69, 12, 8, 1, 3, 0);
			drawBlockLines(b, 101, 12, 8, 1, 3, 1);
			drawBlockLines(b, 69, 13, 8, 2, 3, 2);
			drawBlockLines(b, 93, 13, 8, 2, 3, 4);
			drawBlockLines(b, 69, 14, 8, 2, 3, 6);
			drawBlockLines(b, 93, 14, 8, 2, 3, 8);
			drawBlockLines(b, 69, 15, 8, 5, 3, 10);
			drawBlockLines(b, 61, 16, 8, 7, 3, 15);
			drawBlockLines(b, 61, 17, 8, 7, 3, 21);
			drawBlockLines(b, 61, 18, 8, 7, 3, 27);
			drawBlockLines(b, 61, 19, 8, 7, 3, 33);
			drawBlockLines(b, 61, 20, 8, 7, 3, 39);
			drawBlockLines(b, 61, 21, 8, 7, 3, 45);
			drawBlockLines(b, 61, 22, 8, 7, 1, 51);
			drawBlockLines(b, 61, 23, 8, 7, 3, 57);
			drawBlockLines(b, 69, 24, 8, 5, 3, 63);
			drawBlockLines(b, 69, 25, 8, 5, 3, 68);
			drawBlockLines(b, 69, 26, 8, 5, 3, 73);
			drawBlockLines(b, 69, 27, 8, 5, 3, 78);
			drawBlockLines(b, 69, 28, 8, 5, 3, 83);
			drawBlockLines(b, 77, 29, 8, 3, 3, 88);   
			drawBlockLines(b, 77, 30, 8, 3, 3, 91);
			drawBlockLines(b, 77, 31, 8, 3, 3, 94);
			drawBlockLines(b, 85, 32, 8, 1, 3, 97);
			drawBlockLines(b, 85, 33, 8, 1, 3, 98);
			drawBlockLines(b, 85, 34, 8, 1, 1, 99); 
			break;
		}
	reverse('p');
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

void drawBlockLines(struct block *b, int x1, int y1, int n, int blocks, int hp, int totnum){
	int x2, y_temp = y1, num = totnum, i, j, x = 32; 
		for(j = 0; j < blocks; j++) {
			x2 = x1 + n;
			b[num].xleft = x1;
  	 		b[num].ytop = y1;
   			b[num].xright = x2;
 		    b[num].life = hp;
			setColor(b, num);
            gotoxy(x1, y1);
			for (i = x1; i <= x2; i++) {
				printf("%c", x);
			}
			x1 += n;
			num++;
		}
//			for(i = totnum; i < num ; i++){
//		printf("\n x1, y1, x2, life = %d, %d, %d, %d", b[i].xleft, b[i].ytop, b[i].xright, b[i].life);		
//		}

}		  

// struct block b[NUM_BLOCKS];
// initLevels(b, 2); 
