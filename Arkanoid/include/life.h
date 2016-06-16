#ifndef _Life_H_
#define _Life_H_

struct lives{
    short Lives;
};

void initLife( struct lives * L );
void printLife( struct lives * life );
void addLife( struct lives * life );
void removeLife( struct lives * life );

#endif