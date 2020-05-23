#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DLL 560
#define DLH 561
int main() 
{
  uint8_t *dl,*dll,*dlh;
  uint8_t *dlstart;
  int i;
  dll = 560;
  dlh = 561;
  dl = *dll + *dlh*256;

  dlstart = dl;
  printf("dl:%i",(uint16_t)dl);
  *(dl++) = 70;
  *(dl++)= 42;
  *(dl++) = 0x20;
  *(dl++) = 0x7c;
  for (i=0; i< 20; i++)
    {
      *(dl++) = 70;
    }
  *dl++ = 41;
  *dl++ = ((int)dlstart & 0x00ff);
  *dl++ = ((int)dlstart >> 8);

  /* Write custom displaylist */

  while (1) {}
  return 0;
}
