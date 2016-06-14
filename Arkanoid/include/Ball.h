#ifndef _Ball_H_
#define _Ball_H_

struct BallPos{
    long x,y;
	long xV, yV;
};

void initBall();
void drawBall(struct BallPos * ball);

#endif