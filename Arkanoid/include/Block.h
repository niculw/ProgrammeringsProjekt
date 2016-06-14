//
//  Block.h
//  
//
//  Created by Nicolai Weis on 13/06/16.
//
//

#ifndef Block_h
#define Block_h
#define NUM_BLOCKS 10

struct block {
    int xleft, ytop, xright;
};
void initBlocks(struct block *b, int x1, int y1);


#endif /* Block_h */
