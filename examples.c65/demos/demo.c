
#include <lynx.h>       /* hardware */
#include <lynxlib.h>	/* lynx.olb */
#include <stdlib.h>	/* c.olb */

/* cheesy demo program for cc65 on the atari lynx */
/* written by Kurt Olsen                          */

/* slidly modified 42BS for the latest version of cc65 */

#define register zstatic

/* these macros are defined by the commandline with -D */
/* #define DEMO0 1 */     /* display image for all you weird science fans */
/* #define DEMO1 1 */     /* fill screen with random dots */
/* #define DEMO2 1 */     /* sierpinski triangle */
/* #define DEMO3 1 */     /* random mazes */

#ifdef  DEMO0
extern char image[];
extern char image_scb[];
#asm
		data
_image_scb:
                dc.b $c0                        ; 4 bits/pixel
                dc.b $10                        ; packed , reload size
                dc.b $20                        ; non-collidable
                dc.w 0                          ; link
                dc.w _image                     ; data
                dc.w 0,0                        ; x,y
                dc.w $200,$200                  ; size : x2
                dc.b $01,$23,$45,$67
                dc.b $89,$AB,$CD,$EF            ; palette redir.
		text
#endasm

#endif

#define SCREEN_ADDR 0x8000

uchar pal[32];

main()
{
register int x,y,top;
register uchar i;

/* install irq-handler */
  InitIRQ();
/* install ComLynx-uploader */
  InstallUploader(_62500Bd);
/* enable mikey's interrupt response */
  CLI;

  bzero(pal,32);  /* never assume memory to be zero !!! */

  SetRGB(pal);    /* be sure, all is black */

/* set screen base address */
  SetBuffers(SCREEN_ADDR,(uchar *)0,(uchar *)0);

#ifdef DEMO0
/*
 * demo 0 - draw a picture and scroll it up and down with the
 *          joypad.
 */
{   register int left;

    for (i=0; i < 16; ++i)
      {
      pal[i]=i;
      pal[i+16]=i|i<<4;
      }
    SetRGB(pal);

    hoff = top = 130;
    voff = left = 50;
    while (1)
      {
      DrawSprite(image_scb);
      if (joystick & 0x80) --top;
      if (joystick & 0x40) ++top;
      if (top < 0) top = 0;
      if (top > (206<<1)-101) top = (206<<1)-101;
      voff = top;
      if (joystick & 0x20) --left;
      if (joystick & 0x10) ++left;
      if (left < 0) left = 0;
      if (left > 160) left = 160;
      hoff = left;
      }
}
#endif /* DEMO0 */

#ifdef DEMO1
/*
 * demo 1 - draw random dots
 *          eventually it fills the screen
 */
    while ( ! joystick )
      random();

    for (i=31; i ; --i)
      pal[i]=random();

    pal[0] = pal[16] = 0;

    SetRGB(pal);

    DrawFBox(0,0,160,200,0);

    for (i=0; i < 102; ++i)
      SetPixel(i,i,i);

    for( ; ; )
      {
      x = random() / 206;
      y = random() / 325;
      SetPixel(x,y,random() & 0xf);
      }
#endif /* DEMO1 */

#ifdef DEMO2
    while ( ! joystick )
      random();

    for (i = 31; i ; --i)
      pal[i] = random();

    pal[0] = pal[16] = 0;

    SetRGB(pal);

    DrawFBox(0,0,160,102,0);

    x = random()/205;
    y = random()/325;
    for (i=0; i < 10; ++i)
      {
      top = random();
      if (top < 10922)
                { x = (x+80)>>1; y >>= 1; }
      else if (top < 21845)
                { x >>= 1; y = (y+101)>>1; }
      else
        { x = (x+159)>>1; y = (y+101)>>1; }
      }
    for(;;)
      {
      top = random();
      if (top < 10922)
        { x = (x+80)>>1; y >>= 1; SetPixel(x,y,1); }
      else if (top < 21845)
        { x >>= 1; y = (y+101)>>1; SetPixel(x,y,2); }
      else
        { x = (x+159)>>1; y = (y+101)>>1; SetPixel(x,y,3);}
      }
#endif /* DEMO2 */

#ifdef DEMO3

  DrawFBox(0,0,160,102,0);

  pal[1] = pal[1+16] = 0xff;

  SetRGB(pal);

  for( ;; )
    {
    while ( ! joystick )
      random();

    DrawFBox(0,0,160,102,0);

    maze();

    }
#endif /* DEMO3 */
}

#ifdef DEMO3
/*
 * random maze generator.
 */

#define Xmax (160-2)
#define Ymax (102-2)

uchar done = 0;
uchar x,y,v,w;

maze()
{
  done = 0;

  x = (random()/421)<<1; y = (random()/656)<<1;

  while (!done)
    {
    doseg();
    x = v;
    y = w;
    backup();
    x = v;
    y = w;
    }
}

doseg()
{
register uchar moves,r,flag;

  moves = 1;

  while ( moves )
    {
    moves = 4;
    if ( !x )
     --moves;
    if ( x && GetPixel(x-2,y) )
      --moves;
    if ( !y )
      --moves;
    if ( y  && GetPixel(x,y-2) )
      --moves;
    if (x == Xmax)
      --moves;
    if (x < Xmax && GetPixel(x+2,y) )
      --moves;
    if (y == Ymax)
      --moves;
    if (y < Ymax && GetPixel(x,y+2) )
      --moves;

    if ( ! moves )
      break;

    do {
      flag = 0;

      SetPixel(x, y, 1);
      SetPixel(x+1, y+1, 1);
      r = random()>>13;

      switch(r)
      {
      case 0:
          if (x && ! GetPixel(x-2,y) )
            {
            SetPixel(x-1, y, 1);
            x-= 2;
            flag = 1;
            }
        break;
      case 1:
          if (y && ! GetPixel(x,y-2))
            {
            SetPixel(x, y-1, 1);
            y-= 2;
            flag = 1;
            }
        break;
      case 2:
          if (x < Xmax && !GetPixel(x+2,y))
            {
            SetPixel(x+1, y, 1);
            x+= 2;
            flag = 1;
            }
        break;
      case 3:
          if (y < Ymax && !GetPixel(x,y+2))
            {
            SetPixel(x, y+1, 1);
            y+= 2;
            flag = 1;
            }
        break;
        }
      }while ( flag );
    }
    v = x;
    w = y;
}

backup()
{
register uchar moves;
  moves = 0;

  done = 0;
  while (!moves && !done)
    {
    SetPixel(x+1, y+1, 0);
    if ( x && GetPixel(x-1,y) && GetPixel(x-1,y+1))
    {
      x-= 2;
    }
    else if ( y && GetPixel(x,y-1) && GetPixel(x+1,y-1))
    {
      y-= 2;
    }
    else if (x < Xmax && GetPixel(x+1,y) && GetPixel(x+3,y+1))
    {
      x+= 2;
    }
    else if (y < Ymax && GetPixel(x,y+1) && GetPixel(x+1,y+3))
    {
      y+= 2;
    }
    else
      done = 1;

    moves = 4;
    if (!x)
      --moves;
    else
      if ( GetPixel(x-2,y) )
        --moves;

    if (!y)
      --moves;
    else
      if ( GetPixel(x,y-2) )
        --moves;

    if (x==Xmax)
      --moves;
    else
      if ( GetPixel(x+2,y) )
        --moves;

    if (y==Ymax)
      --moves;
    else
      if ( GetPixel(x,y+2) )
        --moves;
    }
    v = x;
    w = y;
}

#endif /* DEMO3 */
