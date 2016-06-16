#ifndef _angleCalc_h_
#define _angleCalc_h_

struct TVector {
	long x,y;
};

long expand(long i);
void printFix(long i);
void initVector(struct TVector * v, long x, long y);
void rotate(struct BallPos * ball, int a );
void angleCalculation( struct BallPos * ball , int collision );

#endif