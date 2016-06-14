//
//  Block.h
//  
//
//  Created by Nicolai Weis on 13/06/16.
//																     void setLevelBlocks(struct block *b, int x1, int y1, int level, int num)
//

#ifndef Block_h
#define Block_h
#define NUM_BLOCKS 100

struct block {
    int xleft, ytop, xright, life;
};
void setLife(struct block *b, int x1, int y1, int collision);

void setLevelBlocks(struct block *b, int x1, int y1, int level, int num);

void setColor(struct block *b, int num);

void printBlocks(struct block *b, int x1, int y1, int n);

void initBlocks(struct block *b, int x1, int y1, int level, int length);


#endif /* Block_h */
