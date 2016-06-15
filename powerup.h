#ifndef _powerup_h_
#define _powerup_h_

void initPowerup(struct BallPos * ball,struct powerup * p );
void drawPowerup(struct powerup * p);
void despawn((struct powerup * p);
void powerup(int bh,struct powerup * p, struct lives * L, collisionDetect, int STRIKER_WIDTH, BallPos * ball);



#endif
