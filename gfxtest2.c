#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <atari.h>

int init_gfx();

int main()
{
  unsigned char ScreenMemory[9000];
  unsigned char ScreenMemoryText[40];
  void DisplayList = {
    DL_BLK8,
    DL_BLK8,
    DL_LMS(DL_CHR20x8x2),
    ScreenMemoryText,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_GRAPHICS7,
    DL_JVB,
    &DisplayList
};
OS.sdlst = &DisplayList;
 ScreenMemoryText = "PixelGameEngane 2.0 6502";
 while (1) {}
  return 0;
}

int init_gfx()
{
  void 

  return 0;
}
