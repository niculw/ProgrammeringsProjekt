#ifndef _initLevel_h_
#define _initLevel_h_


extern const unsigned char LEVEL_1[51][3];
extern const unsigned char LEVEL_2[51][3];
extern const unsigned char LEVEL_3[51][3];
void drawBorder(int style);

void initLevel( char block[50][3] , short level );
void printBlocks( char block[50][3] );

#endif