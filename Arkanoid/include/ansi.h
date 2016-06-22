#ifndef _ANSI_H_
#define _ANSI_H_

void fgcolor(unsigned char foreground);
void bgcolor(unsigned char background);
void color(unsigned char foreground, unsigned char background);
void resetbgcolor();
void clrscr();
void clreol();
void gotoxy(unsigned char x, unsigned char y);
void goDown( unsigned char c );
void goUp( unsigned char c );
void goRight( unsigned char c );
void goLeft( unsigned char c );
void underline(char on);
void blink(char on);
void reverse(char on);
void window(int x1, int y1, int x2, int y2, char * string, int style);

#endif 
