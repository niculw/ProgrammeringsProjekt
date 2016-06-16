#ifndef _StopWatch_h_
#define _StopWatch_h_

struct time {
	int hour;
	int min;
	int sec;
	int milisec;
	int oldsec;
};

//void timer0int();
void calcTime( struct time * t );
void inittime( struct time * t, int h, int m, int s, int ms, int oldsec);
void keyFunc( char keys, struct time * tid);
void initCounter();
void printtime( struct time * t );

#endif
