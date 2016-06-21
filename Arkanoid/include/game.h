#ifndef _GAME_H_
#define _GAME_H_

struct controlData{
	unsigned int point;
	unsigned char level;
	unsigned int blockCount;
	unsigned char playerLife;
};

void initControl( struct controlData * ctrlData );
void printControlData( struct controlData * ctrlData );
void game();

#endif