#
# makefile for CC65 lynx - runtime library
#

# global macros

CC=$(TOP)/bin/cc65
AS=$(TOP)/bin/ra65
LD=$(TOP)/bin/link65
AR=$(TOP)/bin/libr65
RM=rm -f
CP=cp

BINDIR= $(TOP)/lib

GLOBAL = $(TOP)/runtime/global.m65

CFLAGS=-O

.SUFFIXES: .com .obj .m65 .c

.c.obj:
	$(CC) $(CFLAGS) $<
	$(AS) -o $@ $*.m65
	$(RM) $*.m65

.m65.obj:
	$(AS) -o $@ $(GLOBAL) lynx.m65 $<


LYNX_OBJS = irq.obj setrgb.obj draw_spr.obj flip.obj setbuff.obj swapbuff.obj\
            pixel.obj draw.obj box.obj random.obj upload.obj\
	    to.obj bcd.obj defpal.obj sample.obj eeprom.obj


install : lynx.olb

lynx.olb : $(LYNX_OBJS)
	$(AR) a lynx.olb $?
	$(CP) lynx.olb $(BINDIR)
clean:
	$(RM) errlist *.bak *.obj
	$(RM) lynx.olb
