#ifndef _initLevel_h_
#define _initLevel_h_


extern const unsigned char LEVEL_1[25][22];
//extern const unsigned char LEVEL_2[25][22];
//extern const unsigned char LEVEL_3[25][22];
void drawBorder(int style);

void initLevel( char block[25][22] , short level );
void printBlocks( char block[25][22] );

#endif