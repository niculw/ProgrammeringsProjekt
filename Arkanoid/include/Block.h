//
//  Block.h
//  
//
//  Created by Nicolai Weis on 13/06/16.
//
//

#ifndef Block_h
#define Block_h
#define NUM_BLOCKS

struct block {
    int xleft, ytop, xright;
};

void initBlocks(struct block b[NUM_BLOCKS], int x1, int y1, int x2, int num);

void printBlocks(int x1, int y1);


#endif /* Block_h */
