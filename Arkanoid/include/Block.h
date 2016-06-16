//
//  Block.h
//  
//
//  Created by Nicolai Weis on 13/06/16.
//																     void setLevelBlocks(struct block *b, int x1, int y1, int level, int num)
//

#ifndef Block_h
#define Block_h
#define NUM_BLOCKS 50

struct block {
    int xleft, ytop, xright, life;
};
void updateLife(struct block *b, int x1, int y1, int collision);

//void setLevelBlocks(struct block *b, int x1, int y1, int level, int num);
void initLevels(struct block *b, int level);

void setColor(struct block *b, int num);

//void printBlocks(struct block *b, int x1, int y1, int n, int level, int blocks);

//void initBlocks(struct block *b, int x1, int y1, int level, int length, int blocks);

void drawBlockLines(struct block *b, int x1, int y1, int n, int blocks, int hp, int totnum);


#endif /* Block_h */
