/* demo program for cc65 on the atari lynx */
#include <lynx.h>
#include <lynxlib.h>
#define SCREEN_ADDR (0xfc00-8160)

extern maze();

char pal[] =
{
  0x00,0x0f,0x00,0x00,0x0f,0,0,0,0,0,0,0,0,0,0,0x0f,
  0x00,0x00,0xf0,0x0f,0x0f,0,0,0,0,0,0,0,0,0,0,0xff
};
main()
{
  InitIRQ();
  InstallUploader(_62500Bd);
  CLI;

  SetBuffers(SCREEN_ADDR,(char *)0,(char *)0 );

  SetRGB(pal);

  POKE(5,0);
  for( ;; )
  {
    while (! joystick)
      random();

    DrawFBox(0,0,160,102,0);
    POKE(1,(random()/415)<<1);
    POKE(2,(random()/656)<<1);
    maze();
  }
}
