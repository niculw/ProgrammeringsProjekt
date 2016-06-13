{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red127\green0\blue85;\red0\green80\blue50;\red0\green0\blue192;
\red100\green40\blue128;\red42\green0\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs22 \cf2 #define\cf0  NUM_BLOCKS 50\
\
\cf2 struct\cf0  \cf3 block\cf0  \{\
	\cf2 int\cf0  \cf4 xleft\cf0 , \cf4 ytop\cf0 , \cf4 xright\cf0 , \cf4 ybot\cf0 ;\
\};\
\
\pard\pardeftab720\partightenfactor0
\cf0 \ul \ulc0 printBlocks(\cf2 \ulc2 struct\cf0 \ulc0  \cf3 \ulc3 block\cf0 \ulc0  b[NUM_BLOCKS], \cf2 \ulc2 int\cf0 \ulc0  x1, \cf2 \ulc2 int\cf0 \ulc0  y1, \cf2 \ulc2 int\cf0 \ulc0  color) \{\ulnone \
	\cf2 int\cf0  i, x = 196, y = 179, num = 0, x_temp = x1;\
\
	\cf2 int\cf0  a[6] = \{ 218, 192, 217, 191 \};\
\
	\cf2 while\cf0  (num != NUM_BLOCKS) \{\
		\cf2 int\cf0  y2 = y1 + 1;\
		\cf2 while\cf0  (x1 != 160) \{\
\
			\cf2 int\cf0  x2 = x1 + 5;\
\
			\cf2 for\cf0  (i = y1; i < y2; i++) \{\
				\ul gotoxy(x1, i);\ulnone \
				\cf5 printf\cf0 (\cf6 "%c"\cf0 , y);\
				gotoxy(x2, i);\
				\cf5 printf\cf0 (\cf6 "%c"\cf0 , y);\
			\}\
			gotoxy(x1 + 1, y2);\
			\cf2 for\cf0  (i = x1 + 1; i < x2; i++) \{\
				\cf5 printf\cf0 (\cf6 "%c"\cf0 , x);\
			\}\
			gotoxy(x1 + 1, y1);\
			\cf2 for\cf0  (i = x1 + 1; i < x2; i++) \{\
				\cf5 printf\cf0 (\cf6 "%c"\cf0 , x);\
			\}\
\
			gotoxy(x1, y1);\
			\cf5 printf\cf0 (\cf6 "%c"\cf0 , a[0]);\
			gotoxy(x1, y2);\
			\cf5 printf\cf0 (\cf6 "%c"\cf0 , a[1]);\
			gotoxy(x2, y2);\
			\cf5 printf\cf0 (\cf6 "%c"\cf0 , a[2]);\
			gotoxy(x2, y1);\
			\cf5 printf\cf0 (\cf6 "%c"\cf0 , a[3]);\
\
			x1 += 7;\
			b[num].\cf4 xleft\cf0  = x1;\
			b[num].\cf4 ytop\cf0  = y1;\
			b[num].\cf4 xright\cf0  = x2;\
			b[num].\cf4 ybot\cf0  = y2;\
			num++;\
\
		\}\
		y1 += 3;\
		x1 = x_temp;\
	\ul \}\ulnone \
\}}