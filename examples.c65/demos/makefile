ifndef TOP
export TOP=../..
endif
LD = $(TOP)/bin/link65 -m
CC = $(TOP)/bin/cc65
AS = $(TOP)/bin/ra65
XOPT = $(TOP)/bin/xopt

RM = rm -f
CFLAGS=

export CC65INCLUDE=$(TOP)/include
export CC65LIB=$(TOP)/lib

LIBS = lynx.olb c.olb

.SUFFIXES: .c .obj .m65

.m65.obj:
	$(AS) -o $@ $<

.ONESHELL:
all : demo0.com demo1.com demo2.com demo3.com mazedemo.com sprite.com
	@echo
	echo "Don't forget to press the joypad to begin the demos."
	echo

demo0.com : demo0.obj image.obj
	@echo $@
	@$(LD) -b200 -s512 -o demo0.com demo.obj image.obj $(LIBS)

demo1.com : demo1.obj
	@echo $@
	@$(LD) -b200 -s512 -o demo1.com demo.obj $(LIBS)

demo2.com : demo2.obj
	@echo $@
	@$(LD) -b200 -s512 -o demo2.com demo.obj $(LIBS)

demo3.com : demo3.obj
	@echo $@
	@$(LD) -b200 -s1024 -o demo3.com demo.obj $(LIBS)

mazedemo.com : mazedemo.obj maze.obj
	@echo $@
	@$(LD) -b200 -s512 -o mazedemo.com mazedemo.obj maze.obj $(LIBS)

sprite.com : sprite.obj
	@echo $@
	@$(LD) -b200 -s512 -o sprite.com sprite.obj $(LIBS)

.ONESHELL:
clean :
	@$(RM) *.obj
	$(RM) *.com
	$(RM) *.spr
	$(RM) *.bak
	$(RM) *.map

.ONESHELL:
demo0.obj : demo.c
	@$(CC) $(CFLAGS) -DDEMO0 demo.c
	$(XOPT) demo.m65
	$(AS) demo.m65
	$(RM) demo.m65

.ONESHELL:
demo1.obj : demo.c
	@$(CC) $(CFLAGS) -DDEMO1 demo.c
	$(XOPT) demo.m65
	$(AS) demo.m65
	$(RM) demo.m65

.ONESHELL:
demo2.obj : demo.c
	@$(CC) $(CFLAGS) -DDEMO2 demo.c
	$(XOPT) demo.m65
	$(AS) demo.m65
	$(RM) demo.m65

.ONESHELL:
demo3.obj : demo.c
	@$(CC) $(CFLAGS) -DDEMO3 demo.c
	$(XOPT) demo.m65
	$(AS) demo.m65
	$(RM) demo.m65

.ONESHELL:
sprite.obj : sprite.c sprite.h test.h
	@$(CC) $(CFLAGS)  sprite.c
	$(XOPT) sprite.m65
	$(AS) sprite.m65
	$(RM) sprite.m65

.ONESHELL:
mazedemo.obj : mazedemo.c
	@$(CC) $(CFLAGS) mazedemo.c
	$(XOPT) mazedemo.m65
	$(AS) mazedemo.m65
	$(RM) mazedemo.m65

image.obj : image.raw
	@sprpck -t0 -p0 -i160206 image.raw image
