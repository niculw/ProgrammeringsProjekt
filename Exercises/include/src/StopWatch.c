#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ANSI.h"
#include "StopWatch.h"

int milisec = 0;

#pragma interrupt 
void timer0int() { 
	milisec += 10;
}

void calcTime( struct time * t ){
	if (milisec < 990 ) {
		(*t).milisec = milisec;
	} else {
		(*t).milisec = 0;
		milisec = 0;
		if ((*t).sec < 59){
			(*t).sec++ ;
		} else {
			(*t).sec = 0;
			if ((*t).min < 59){
				(*t).min++;
			} else {
				(*t).min = 0;
				(*t).hour++;
			}
		}
	}
}

void inittime( struct time * t, int h, int m, int s, int ms, int oldsec){
	(*t).hour = h;
	(*t).min = m;
	(*t).sec = s;
	(*t).milisec = ms;
	(*t).oldsec = oldsec;
}

void keyFunc( char keys, struct time * tid){
static int startstop = 0;
	switch (keys){
		case 0x01 : 
			if (0 == startstop){
				EI();
				startstop = 1;
			} else {
				DI();
				startstop = 0;
			}
			break;
		case 2 :
			if (startstop == 1){
					gotoxy(8,7);
					printf("Split time 1 is: %d:%02d:%02d,%02d \n", (*tid).hour ,(*tid).min ,(*tid).sec ,(*tid).milisec / 10);
			}
			break;
		case 4 : 
			if (startstop == 1){
				gotoxy(8,8);
				printf("Split time 2 is: %d:%02d:%02d,%02d \n", (*tid).hour ,(*tid).min ,(*tid).sec ,(*tid).milisec / 10);
			}
			break;
		case 6 : 
			DI();
			startstop = 0;
			inittime( tid, 0, 0, 0, 0, 0);
			milisec = 0;
			gotoxy(25 ,6);
			printf("0:00:00,--");
			gotoxy(25 ,7);
			printf("-:--:--,--");
			gotoxy(25 ,8);
			printf("-:--:--:--");
			break;
	}
}

void initCounter(){		
/*
	DI();					// disable inteupt
	SET_VECTOR(TIMER0, timer0int);
	T0CTL &= 0x00;  		// disable timer
	T0RH = 0x5A;			// set reload high value 
	T0RL = 0x00;			// set reload low value
	T0H = 0x00;				// timer byte high = 00000000
	T0L = 0x01;				// timer byte low = 00000001
	T0CTL &= 0x18;			// set prescale value til 011
	T0CTL |= 0x18;			// 
	T0CTL |= 0x01;			// Continuous mode
	IRQ0ENH &= 0x00;		// medium prioitet
	IRQ0ENL |= 0x21;		// medium prioitet
	T0CTL |= 0x80;  		// enable timer
	//T0CTL |= 0x99;			// enable timer // 1001 1001
	*/
}

void printtime( struct time * t ){
	if ( (*t).oldsec != (*t).sec){
		gotoxy( 8 , 6 );
		printf("Time is:         %d:%02d:%02d,--\n",(*t).hour,(*t).min,(*t).sec);
		(*t).oldsec = (*t).sec;
	}
}

	/*
	newkey = readKey();
	if(oldkey != newkey){
		oldkey = newkey;
		keyFunc(newkey, &watch);
	}
	*/

