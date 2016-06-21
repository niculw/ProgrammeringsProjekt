#ifndef _initLevel_h_
#define _initLevel_h_


extern rom const unsigned char LEVEL_1[25][22];
extern rom const unsigned char LEVEL_2[25][22];
extern rom const unsigned char LEVEL_3[25][22];
void drawBorder(int style);

//void removeBlockLife( char block[25][22], unsigned char i, unsigned char j );
void removeBlockLife( char * block, struct controlData * ctrlData );
void updateBlock( char * block , unsigned char i, unsigned char j, struct controlData * ctrlData);
void initLevel( char block[25][22] , struct controlData * ctrlData );
void printBlocks( char block[25][22], struct controlData * ctrlData );
void clearLevel(  );
#endif