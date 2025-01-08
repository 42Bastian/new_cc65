#
# makefile for CC65 runtime library
#
# local bin path

# global macros
ifndef TOP
TOP=..
endif

CC=$(TOP)/bin/cc65
OP=$(TOP)/bin/xopt
AS=$(TOP)/bin/ra65
LD=$(TOP)/bin/link65 -m
AR=$(TOP)/bin/libr65
RM=rm -f

export CC65INCLUDE=$(TOP)/include
export CC65LIB=$(TOP)/lib

CFLAGS=

.SUFFIXES: .com .ttp .o .obj .m65 .c

.ONESHELL:
%.obj: %.c
	@$(CC) $<
	$(OP) $*.m65
	$(AS) $*.m65
	$(RM) $*.m65

%.obj: %.m65
	$(AS) $<

all:	minimal.com mandel.com gfxtest.com

gfxtest.com : gfxtest.obj
	@echo $@
	@$(LD) -b200 -s512 -o $*.com $*.obj lynx.olb

mandel.com : mandel.obj
	@echo $@
	@$(LD) -b4000 -B200 -s512 -o $*.com $*.obj lynx.olb

minimal.com : minimal.obj title.obj
	@echo $@
	@$(LD) $(LDFLAGS) -b200 -s512 -o $*.com $*.obj lynx.olb title.obj

minimal.obj : minimal.c title.obj

title.obj:
	@sprpck -c -p0 title.pcx

.ONESHELL:
clean :
	@$(RM) *.com
	$(RM) *.obj
	$(RM) *.pal
	$(RM) *.spr
	$(RM) *.bak
	$(RM) *.map
	$(RM) *.m65
