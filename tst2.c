#include <atari.h>
#include <atari_screen_charmap.h>
#include <string.h>
#include <stdlib.h>

void drawTest(int x,int y,char c);
void draw(int x, int y, char c);
void drawLine(int x1, int y1, int x2, int y2, char c);

int main() {
  unsigned char *ip;
  int i,j;
  char c[ ] ="PixelGameEngine_2.0";
  unsigned char DisplayList[150] = {DL_BLK8,
      DL_LMS(DL_CHR20x8x2),
      0x00,0x60,
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
      DL_LMS(DL_GRAPHICS7),
      0x14,0x6a,
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
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_BLK1,
      DL_JVB,00,00,
    };
 
  DisplayList[138] = ((char)&DisplayList & 0x00ff);
  DisplayList[139] = ((char)&DisplayList >> 8);
  
  /* ip=0x6000;
  for (i=0x6000; i < 0xd000;i++) {
    *(ip++)=0;
    } */
  OS.sdlst = &DisplayList;
  ip=0x6000; 
  for (i=0; i < 400;i++) {
    *(ip++) = 65;
  }
  ip=0x6000;
  for (i=0; i < strlen(c); i++) {
    *(ip++)=c[i];
  }
  while (1) {
    for (i=0; i < 10; i++) {
      for (j=0; j < 7; j++)
	drawTest(i, j, rand() % 4);
    }

 }
  return 0;
}
void drawTest(int x,int y,char c) {
  int px,ix,iy;
  char *screenptr,pd;
  if (c==0) 
    pd = 0;
  else if (c==1)
    pd = 0x55;
  else if (c==2)
    pd = 0xaa;
  else if (c==3)
    pd = 0xff;

  screenptr = 0x6014;
  px = x / 16;
  switch (y) {
  case 1:
    screenptr += 640;
    break;
  case 2:
    screenptr += 1280;
    break;
  case 3:
    screenptr += 1920;
    break;
  case 4:
    screenptr += 2560;
    break;
  case 5:
    screenptr += 3200;
    break;
  case 6:
    screenptr += 3840;
    break;
  }  
screenptr += x << 2;
  for (iy=0; iy < 16; iy++) {
    *(screenptr++)=pd;
    *(screenptr++)=pd;
    *(screenptr++)=pd;
    *(screenptr++)=pd;
    screenptr += 36;
 }
  
}

  void drawLine(int x1, int y1, int x2, int y2, char c) {
    int tmpx,tmpy,i,xp,xp2,d,d1,d2;
    char *screenptr;
    screenptr = 0x6014;
    if (x1 == x2) /* Vertical line */
      {
	if (y1 > y2) {
	  tmpy = y1;
	  tmpx = x1;
	  y1 = y2;
	  x1 = x2;
	  y2 = tmpy;
	  x2 = tmpx;
	}
	screenptr += y1 * 40 + (x1 >> 2);
	xp = x1 % 4;
	d = ( c << (8-xp*2));
	  for (i=0; i < (y2-y1); i++) {
	    *screenptr = d;
	    screenptr += 40;
	  } 
      }
    else if (y1 == y2 ) /* Horisontal line */
      {
	if (x1 > x2) {
	  tmpx = x1;
	  tmpy = y2;
	  x1 = x2;
	  y1 = y2;
	  x2 = tmpx;
	  y2 = tmpy;
	}
	px  = x1 % 4;
	px2 = x2 % 4;
	screenptr += y1 * 40 + (x1 >> 2);
	d   = (c << 6) | (c << 4) | (c << 2) | c;
	d2  = d1 = d;
	d1  &= (0xff >> (px * 2));
	d2 &= (0xff << (8 - px2 *2));
	*screenptr++ = d1;
	for (i=0; i < ((x2-x1) % 4); i++) {
	  *(screenptr++) = d;
	}
	*screenptr = d2;
      }
  }
  void draw(int x, int y, char c) {

  }
