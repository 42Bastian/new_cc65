#
# makefile for CC65 runtime library
#
# local bin path

# global macros

CC=cc65
OP=xopt
AS=ra65
LD=link65 -m
AR=libr65
RM=rm -f

CFLAGS=

.SUFFIXES: .com .ttp .o .obj .m65 .c

%.obj: %.c
	CC65INCLUDE=../include $(CC) $<
	$(OP) $*.m65
	$(AS) $*.m65
#	$(RM) $*.m65

%.obj: %.m65
	$(AS) $<

all:	minimal.com mandel.com gfxtest.com

gfxtest.com : gfxtest.obj
	CC65LIB=../lib $(LD) -b200 -s512 -o $*.com $*.obj lynx.olb

mandel.com : mandel.obj
	CC65LIB=../lib $(LD) -b4000 -B200 -s512 -o $*.com $*.obj lynx.olb

minimal.com : minimal.obj title.obj
	CC65LIB=../lib $(LD) $(LDFLAGS) -b200 -s512 -o $*.com $*.obj lynx.olb title.obj

minimal.obj : minimal.c title.obj

title.obj:
	sprpck -c -p0 title.pcx

clean :
	$(RM) *.com
	$(RM) *.obj
	$(RM) *.pal
	$(RM) *.spr
	$(RM) *.bak
	$(RM) *.map
	$(RM) *.m65
