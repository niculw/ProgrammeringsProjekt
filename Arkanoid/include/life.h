#ifndef _Life_H_
#define _Life_H_

struct lives{
    short Lives;
};

void printLife( struct controlData * ctrlData );
void addLife( struct controlData * ctrlData );
void removeLife( struct controlData * ctrlData );

#endif