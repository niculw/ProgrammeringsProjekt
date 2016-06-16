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
int i;
reverse('o');
	if(level == 1){
			drawBlockLines(b, 77, 9, 8, 2, 3, 0);
			drawBlockLines(b, 69, 10, 8, 4, 2, 2);
			drawBlockLines(b, 61, 11, 8, 6, 2, 6);
			drawBlockLines(b, 53, 12, 8, 8, 1, 12);
			drawBlockLines(b, 45, 13, 8, 10, 1, 20);
			drawBlockLines(b, 37, 14, 8, 12, 1, 32);

	} else if(level == 2){
			drawBlockLines(b, 13, 12, 8, 19, 3, 0);
 		    drawBlockLines(b, 13, 13, 8, 19, 2, 19);
			drawBlockLines(b, 13, 14, 8, 19, 2, 38);
			drawBlockLines(b, 13, 15, 8, 19, 1, 57);
	} else if(level == 3){
		  	drawBlockLines(b, 69, 12, 8, 1, 1, 0);
			drawBlockLines(b, 101, 12, 8, 1, 1, 1);
			drawBlockLines(b, 69, 13, 8, 2, 1, 2);
			drawBlockLines(b, 93, 13, 8, 2, 1, 4);
			drawBlockLines(b, 69, 14, 8, 2, 1, 6);
			drawBlockLines(b, 93, 14, 8, 2, 1, 8);
			drawBlockLines(b, 69, 15, 8, 5, 1, 10);
			drawBlockLines(b, 61, 16, 8, 6, 1, 15);
			drawBlockLines(b, 61, 17, 8, 6, 1, 21);
			drawBlockLines(b, 61, 18, 8, 6, 1, 27);
			drawBlockLines(b, 61, 19, 8, 6, 1, 33);
			drawBlockLines(b, 61, 20, 8, 6, 1, 39);
			drawBlockLines(b, 61, 21, 8, 6, 1, 45);
			drawBlockLines(b, 61, 22, 8, 6, 1, 51);
			drawBlockLines(b, 61, 23, 8, 6, 1, 57);
			drawBlockLines(b, 69, 24, 8, 5, 1, 63);
			drawBlockLines(b, 69, 25, 8, 5, 1, 68);
			drawBlockLines(b, 69, 26, 8, 5, 1, 73);
			drawBlockLines(b, 69, 27, 8, 5, 1, 78);
			drawBlockLines(b, 69, 28, 8, 5, 1, 83);
			drawBlockLines(b, 77, 29, 8, 3, 1, 88);   
			drawBlockLines(b, 77, 30, 8, 3, 1, 91);
			drawBlockLines(b, 77, 31, 8, 3, 1, 94);
			drawBlockLines(b, 85, 32, 8, 1, 1, 97);
			drawBlockLines(b, 85, 33, 8, 1, 1, 98);
			drawBlockLines(b, 85, 34, 8, 1, 1, 99); 
		

			


		
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
			for(i = totnum; i < num ; i++){
		printf("\n x1, y1, x2, life = %d, %d, %d, %d", b[i].xleft, b[i].ytop, b[i].xright, b[i].life);
		
		}

}		  

// struct block b[NUM_BLOCKS];
// initLevels(b, 2); 
