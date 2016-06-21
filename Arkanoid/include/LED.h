#ifndef _LED_H_
#define _LED_H_


void LEDinit();
void initVideoBuffer( char videoBuffer[5][6] );
void LEDsetString( char videoBuffer[5][6], unsigned int points );
void mellemled( char string[], int n);
void LEDupdate( char videoBuffer[5][6] );
void refreshDisplay();

#endif 
