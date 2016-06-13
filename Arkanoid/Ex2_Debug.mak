#
# ZDS II Make File - Ex2, Debug
#

CC = @C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\bin\eZ8cc
ASM = @C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\bin\eZ8asm
LINK = @C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\bin\eZ8link
LIB = @C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\bin\eZ8lib

CFLAGS =  \
 -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug  \
 -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY  \
 -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -define:_SIMULATE  \
 -doublesize:32 -NOexpmac -floatsize:32 -NOfplib -genprintf  \
 -NOglobalcopy -NOglobalcse -NOglobalfold -intrinsic -intsize:16  \
 -intsrc -NOjmpopt -NOkeepasm -NOkeeplst -NOlist -NOlistinc  \
 -localcopy -localcse -localfold -longsize:32 -NOloopopt  \
 -maxerrs:50 -model:L -NOoptlink -optsize -peephole -NOpromote  \
 -quiet -regvar -revaa -NOsdiopt -shortsize:16  \
 -stdinc:"C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std;C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog;C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\Z8Encore_F640X"  \
 -strict  \
 -usrinc:"M:\Documents\30010_Programerings_Projekt\PArkanoid\include;M:\Documents\30010_Programerings_Projekt\Project;M:\Documents\30010_Programerings_Projekt\Project\include;C:\Users\S143217\Desktop\Project\include;C:\Users\S143217\Desktop\Arkanoid\include;Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include"  \
 -NOwatch -cpu:Z8F6403  \
 -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -define:_SIMULATE=1 -include:C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std;C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog;C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\Z8Encore_F640X -revaa"

AFLAGS =  \
 -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1  \
 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1  \
 -define:_SIMULATE=1 -genobj -NOigcase  \
 -include:"C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std;C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog;C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\Z8Encore_F640X"  \
 -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt  \
 -warn -NOzmasm -revaa -cpu:Z8F6403

OUTDIR = Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\

Debug: Ex2

deltarget: 
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Ex2.lod  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Ex2.lod

clean: 
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Ex2.lod  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Ex2.lod
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\zsldevinit.obj  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\zsldevinit.obj
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\main.obj  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\main.obj
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\ansi.obj  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\ansi.obj
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\lut.obj  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\lut.obj
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\LED.obj  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\LED.obj
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\StopWatch.obj  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\StopWatch.obj
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\initLevel.obj  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\initLevel.obj
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Striker.obj  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Striker.obj
	@if exist Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Block.obj  \
            del Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Block.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\zsldevinit.obj  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\main.obj  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\ansi.obj  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\lut.obj  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\LED.obj  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\StopWatch.obj  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\initLevel.obj  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Striker.obj  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Block.obj

Ex2: $(OBJS)
	 $(LINK)  @Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Ex2_Debug.linkcmd

Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\zsldevinit.obj :  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\zsldevinit.asm  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\ez8dev.inc  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\zsldevinit.asm

Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\main.obj :  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\ANSIproject\main.c  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\format.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdarg.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\string.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\defines.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\dmadefs.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\eZ8.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\gpio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\sio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\uart.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\uartdefs.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\Block.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\LED.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\StopWatch.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\Striker.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\ansi.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\initLevel.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\lut.h
	 $(CC)  $(CFLAGS) Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\ANSIproject\main.c

Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\ansi.obj :  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\ansi.c  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\format.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdarg.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdio.h
	 $(CC)  $(CFLAGS) Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\ansi.c

Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\lut.obj :  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\lut.c  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\lut.h
	 $(CC)  $(CFLAGS) Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\lut.c

Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\LED.obj :  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\LED.c  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\format.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdarg.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\defines.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\dmadefs.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\eZ8.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\gpio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\sio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\uart.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\uartdefs.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\charset.h
	 $(CC)  $(CFLAGS) Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\LED.c

Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\StopWatch.obj :  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\StopWatch.c  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\format.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdarg.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\defines.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\dmadefs.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\eZ8.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\gpio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\sio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\uart.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\uartdefs.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\ansi.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\StopWatch.h
	 $(CC)  $(CFLAGS) Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\StopWatch.c

Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\initLevel.obj :  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\initLevel.c  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\format.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdarg.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdio.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\ansi.h
	 $(CC)  $(CFLAGS) Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\initLevel.c

Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Striker.obj :  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\Striker.c  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\format.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdarg.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdio.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\Striker.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\ansi.h
	 $(CC)  $(CFLAGS) Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\Striker.c

Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\Block.obj :  \
            Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\Block.c  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\format.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdarg.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\std\stdio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\defines.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\dmadefs.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\eZ8.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\gpio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\sio.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\uart.h  \
            C:\PROG~FBU\ZiLOG\ZDSI~VVT.3\include\zilog\uartdefs.h  \
            Z:\Users\NICO~VZA\PROG~VMQ\Arkanoid\include\ansi.h
	 $(CC)  $(CFLAGS) Z:\Users\NicolaiWeis\ProgrammeringsProjekt\Arkanoid\include\src\Block.c

