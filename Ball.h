#ifndef _Ball_H_
#define _Ball_H_

struct BallPos{
    	int x,y;
	int xV, yV;
}

void initBall();
void drawBall(struct Ballpos * ball, int x, int y, int xV, int yV);

#endif