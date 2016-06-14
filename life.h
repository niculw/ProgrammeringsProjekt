#ifndef _Life_H_
#define _Life_H_

struct lives{
    int Life;
};

void initLife(struct live * L);
void lifeChanger(struct lives * L, int collisionDetect, int Extra);

#endif