#
# ZDS II Make File - Ex2, Debug
#

CC = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32
#   -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy
#   -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc -NOjmpopt
#   -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy -localcse
#   -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L -NOoptlink
#   -optsize -peephole -NOpromote -quiet -regvar -revaa -NOsdiopt
#   -shortsize:16
#   -stdinc:"c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict
#   -usrinc:"M:\Documents\30010_Programerings_Projekt\Project\include;M:\Documents\30010_Programerings_Projekt\Project;C:\Users\S143217\Desktop\Project\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\S143217\Desktop\Project\Ex2_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\S143217\Desktop\Project\Ex2_Debug.asmsw

OUTDIR = C:\Users\S143217\Desktop\Project\

Debug: Ex2

deltarget: 
	@if exist C:\Users\S143217\Desktop\Project\Ex2.lod  \
            del C:\Users\S143217\Desktop\Project\Ex2.lod

clean: 
	@if exist C:\Users\S143217\Desktop\Project\Ex2.lod  \
            del C:\Users\S143217\Desktop\Project\Ex2.lod
	@if exist C:\Users\S143217\Desktop\Project\zsldevinit.obj  \
            del C:\Users\S143217\Desktop\Project\zsldevinit.obj
	@if exist C:\Users\S143217\Desktop\Project\main.obj  \
            del C:\Users\S143217\Desktop\Project\main.obj
	@if exist C:\Users\S143217\Desktop\Project\ansi.obj  \
            del C:\Users\S143217\Desktop\Project\ansi.obj
	@if exist C:\Users\S143217\Desktop\Project\lut.obj  \
            del C:\Users\S143217\Desktop\Project\lut.obj
	@if exist C:\Users\S143217\Desktop\Project\LED.obj  \
            del C:\Users\S143217\Desktop\Project\LED.obj
	@if exist C:\Users\S143217\Desktop\Project\StopWatch.obj  \
            del C:\Users\S143217\Desktop\Project\StopWatch.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\S143217\Desktop\Project\zsldevinit.obj  \
            C:\Users\S143217\Desktop\Project\main.obj  \
            C:\Users\S143217\Desktop\Project\ansi.obj  \
            C:\Users\S143217\Desktop\Project\lut.obj  \
            C:\Users\S143217\Desktop\Project\LED.obj  \
            C:\Users\S143217\Desktop\Project\StopWatch.obj

Ex2: $(OBJS)
	 $(LINK)  @C:\Users\S143217\Desktop\Project\Ex2_Debug.linkcmd

C:\Users\S143217\Desktop\Project\zsldevinit.obj :  \
            C:\Users\S143217\Desktop\Project\zsldevinit.asm  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\S143217\Desktop\Project\zsldevinit.asm

C:\Users\S143217\Desktop\Project\main.obj :  \
            C:\Users\S143217\Desktop\Project\ANSIproject\main.c  \
            C:\Users\S143217\Desktop\Project\include\LED.h  \
            C:\Users\S143217\Desktop\Project\include\STOPWA~1.H  \
            C:\Users\S143217\Desktop\Project\include\ansi.h  \
            C:\Users\S143217\Desktop\Project\include\lut.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STRING.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\S143217\Desktop\Project\ANSIproject\main.c

C:\Users\S143217\Desktop\Project\ansi.obj :  \
            C:\Users\S143217\Desktop\Project\include\src\ansi.c  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\S143217\Desktop\Project\include\src\ansi.c

C:\Users\S143217\Desktop\Project\lut.obj :  \
            C:\Users\S143217\Desktop\Project\include\src\lut.c  \
            C:\Users\S143217\Desktop\Project\include\lut.h
	 $(CC)  $(CFLAGS) C:\Users\S143217\Desktop\Project\include\src\lut.c

C:\Users\S143217\Desktop\Project\LED.obj :  \
            C:\Users\S143217\Desktop\Project\include\src\LED.c  \
            C:\Users\S143217\Desktop\Project\include\charset.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\S143217\Desktop\Project\include\src\LED.c

C:\Users\S143217\Desktop\Project\StopWatch.obj :  \
            C:\Users\S143217\Desktop\Project\include\src\StopWatch.c  \
            C:\Users\S143217\Desktop\Project\include\ansi.h  \
            C:\Users\S143217\Desktop\Project\include\STOPWA~1.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\S143217\Desktop\Project\include\src\StopWatch.c

