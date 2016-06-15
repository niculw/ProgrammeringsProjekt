#ifndef _Life_H_
#define _Life_H_

struct lives{
    int Lives;
};

void initLife(struct lives * L);
void lifeChanger(struct lives * L, int collisionDetect, int Extra);

#endif