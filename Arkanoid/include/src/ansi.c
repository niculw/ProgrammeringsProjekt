#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#define ESC 0x1B

void fgcolor( unsigned char foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  unsigned char type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(int background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color      
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/ 

  printf("%c[%dm", ESC, background+40);
}

void color(unsigned char foreground, unsigned char background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  unsigned char type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);  
}

void clrscr(){
	printf("%c[2J",ESC);
}

void clreol(){
	printf("%c[K",ESC);
}

void gotoxy(unsigned char x, unsigned char y) {
	printf("%c[%d;%dH", ESC, y, x);
}

void goDown( unsigned char c ) {
	printf("%c[%dB", ESC ,c);
}

void goUp( unsigned char c ) {
	printf("%c[%dA", ESC ,c);
}

void goRight( unsigned char c ) {
	printf("%c[%dC", ESC ,c);
}

void goLeft( unsigned char c ) {
	printf("%c[%dD", ESC ,c);
}

void underline(char on){
	int x;
	if (on == 'o'){
	 	x = 4;
	}else{
		x = 24;
	}
	printf("%c[%dm", ESC, x);
}

void blink(char on){
	int x;
	if (on == 'o'){
	 	x = 5;
	}else{
		x = 25;
	}
	printf("%c[%dm", ESC, x);
}

void reverse(char on){
	int x;
	if (on == 'o'){
	 	x = 7;
	}else{
		x = 27;
	}
	printf("%c[%dm", ESC, x);
}

void window(int x1, int y1, int x2, int y2, char * string, int style){ 
	int x, y;
	int i;
	int a[2][6] = {{218, 192, 217, 191, 180, 195},
			   {201, 200, 188, 187, 185, 204}};
	
	if (style == 0){
		x = 196;     //196
		y = 179;
	    // højrne top v, ned v, ned h, top h, overskrift v, overskift h
	} else if (style == 1){
		x = 205;
		y = 186; 
    // højrne top v, ned v, ned h, top h, overskrift v, overskift h
	}
	for (i = y1 + 1; i < y2; i++){
		gotoxy(x1, i);
		printf("%c",y);
		gotoxy(x2, i);
		printf("%c",y);
	}
	gotoxy(x1+1,y2);
	for (i = x1 + 1; i < x2; i++){
		printf("%c",x);	
	}
	gotoxy(x1, y1);
	printf("%c", a[style][0]);
	gotoxy(x1, y2);
	printf("%c", a[style][1]);
	gotoxy(x2, y2);
	printf("%c", a[style][2]);
	gotoxy(x2, y1);
	printf("%c", a[style][3]);
	gotoxy(x1+1,y1);
	printf("%c", a[style][4]);
	gotoxy(x2-1,y1);
	printf("%c", a[style][5]);
	reverse('o');
	gotoxy(x1+2,y1);
	for (i = x1+2; i < x2-1; i++) {		///// sætter hele top baren i windows til reverse colors
		printf(" ");
	}
	gotoxy(x1+3,y1);
	for (i = 0; *string != '\0' && i < x2-x1-5; i++){
		printf("%c", *string);	
		string++;
	}
	reverse('p');
}