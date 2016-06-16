#ifndef _ANSI_H_
#define _ANSI_H_

void fgcolor(int foreground);
void bgcolor(int background);
void color(int foreground, int background);
void resetbgcolor();
void clrscr();
void clreol();
void gotoxy(int x, int y);

void goDown( short c );
void goUp( short c );
void goRight( short c );
void goLeft( short c );
void underline(char on);
void blink(char on);
void reverse(char on);
void window(int x1, int y1, int x2, int y2, char * string, int style);

#endif 
