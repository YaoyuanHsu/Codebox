#include <AT89X52.h>
#include <stdlib.h>

#define   s     65536
#define   T     11059200/12
#define   t     T/2

#define	  DO	s-t/(523/2)
#define	  RE	s-t/(587/2)
#define	  MI	s-t/(659/2)
#define   FA	s-t/(698/2)
#define	  SO	s-t/(785/2)
#define	  LA	s-t/(880/2)
#define	  TI	s-t/(998/2)
#define   DOH   s-t/523
#define   REH   s-t/587
#define	  MIH   s-t/659
#define   FAH   s-t/698
#define   SOH   s-t/785
#define   LAH   s-t/880
#define   TIH   s-t/998

unsigned int Table1[] = {TI,LA,SO,LA,TI,TI,TI,0,LA,LA,LA,0,TI,REH,REH};
//unsigned int Table1[] = {TI,LA,SO,LA,TI,TI,TI,0,LA,LA,LA,0,TI,REH,REH,0,TI,LA,SO,LA,TI,TI,TI,0,LA,LA,TI,LA,SO};
unsigned int Table2[] = {SO,MI,MI,0,FA,RE,RE,0,DO,RE,MI,FA,SO,SO,SO};
//unsigned int Table2[] = {SO,MI,MI,0,FA,RE,RE,0,DO,RE,MI,FA,SO,SO,SO,0,SO,MI,MI,0,FA,RE,RE,0,DO,MI,SO,SO,MI};
unsigned int Table3[] = {TI,TI,DOH,REH,REH,DOH,TI,LA,SO,SO,LA,TI,TI,LA,LA};
//unsigned int Table3[]= {};
unsigned int Song[16]= {0};
unsigned int length;
unsigned int copylength1 = sizeof(Table1) / sizeof(Table1[0]);
unsigned int copylength2 = sizeof(Table2) / sizeof(Table2[0]);
unsigned int copylength3 = sizeof(Table3) / sizeof(Table3[0]);

unsigned int temp;

void T0_int(void) interrupt 1
{
  TR0=0;
  TL0 = temp;
  TH0 = temp >>8;
  TR0=1;
  P3_2 =!P3_2;
}

void delay_1m(unsigned int dly)
{
  int count;
  while(dly != 0)
  {
    count=120;
      while(count>0)
        count--;
    dly--;
  }
}

void setsong()
{
    unsigned int i;
	while (P0_5 & P0_6 & P0_7)
        ;
    if (!P0_5) {
        for (i = 0; i < copylength3; i++)
            Song[i] = Table3[i];
        length = copylength3;
        return;
    }
    if (!P0_6) {
        for (i = 0; i < copylength2; i++)
            Song[i] = Table2[i];
        length = copylength2;
        return;
    }
    if (!P0_7) {
        for (i = 0; i < copylength1; i++)
            Song[i] = Table1[i];
        length = copylength1;
        return;
    }
}

void main()
{
  unsigned char i;
  IP=0x02;
  IE=0x82;
  TMOD=0x01;
  P2 = 0xFF;
  while(1)
  {
    setsong();
    for(i=0;i<=length;i++)
    {
	  temp=Song[i];
	  switch (temp) {
        case DO:  P2_7 = 0;  P1 = 0xF9;  break;
        case RE:  P2_6 = 0;  P1 = 0xA4;  break;
        case MI:  P2_5 = 0;  P1 = 0xB0;  break;
        case FA:  P2_4 = 0;  P1 = 0x99;  break;
        case SO:  P2_3 = 0;  P1 = 0x92;  break;
        case LA:  P2_2 = 0;  P1 = 0x82;  break;
        case TI:  P2_1 = 0;  P1 = 0xF8;  break;
        case DOH: P2_7 = 0, P2_6 = 0;  P1 = 0x79;  break;
        case REH: P2_6 = 0, P2_5 = 0;  P1 = 0x24;  break;
        case MIH: P2_5 = 0, P2_4 = 0;  P1 = 0x30;  break;
        case FAH: P2_4 = 0, P2_3 = 0;  P1 = 0x19;  break;
        case SOH: P2_3 = 0, P2_2 = 0;  P1 = 0x12;  break;
        case LAH: P2_2 = 0, P2_1 = 0;  P1 = 0x02;  break;
        case TIH: P2_1 = 0, P2_0 = 0;  P1 = 0x78;  break;
      }
	  TL0=temp;
	  TH0=temp>>8;
	  TR0=1;
	  delay_1m(500);
	  TR0=0;
	  P2 = 0xFF;
	  P1 = 0xFF;
    }
  }
}

