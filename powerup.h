#ifndef _powerup_h_
#define _powerup_h_

struct powerup{
    int x,y,xV,yV;
};

void initPowerup(struct BallPos * ball,struct powerup * p );
void drawPowerup(char select);
void despawn((struct powerup * p);
void powerup(int bh,struct powerup * p, struct lives * L, collisionDetect, int STRIKER_WIDTH, BallPos * ball);



#endif
