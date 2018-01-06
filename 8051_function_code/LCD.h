#include <at89x52.h>

sbit     RW  = P3^6;
sbit     RS  = P3^7;
sbit     EN  = P3^5;
#define  LCD_DATA   P2
#define  d_time     100

unsigned char  	code  String1[]= " 8051 Music Box ";
unsigned char String2[] = "     START      ";
unsigned char copystring1[] = "1.Lamb";
unsigned char copystring2[] = "2.Bee ";
unsigned char copystring3[] = "3.Joy ";

void  delay_time(int k)
{
  while (k>0)
    k--;
}

void  LCD_COMMAND(char temp)
{
  delay_time(d_time);
  RS=0;
  delay_time(d_time);
  LCD_DATA=temp;
  delay_time(d_time);
  EN=1;
  delay_time(d_time);
  EN=0;
}

void LCD_Clear(void)
{
  LCD_COMMAND(0x01);
}

void LCD_Home(void)
{
  LCD_COMMAND(0x02);
}

void LCD_Display_Word(char  LCD_WORD)
{
  delay_time(d_time);
  RS=1;                   //  設定存取資料暫存器
  delay_time(d_time);
  LCD_DATA=LCD_WORD;      //  送出LCD資料字元
  delay_time(d_time);
  EN=1;
  delay_time(d_time);
  EN=0;
}

void LCD_Display_String(char  *s1)
{
  unsigned char  i;
  for (i=0;i<50;i++)
  {
    if (*(s1+i)=='\0')
      break;  //判斷字串是否已經傳送完畢
    LCD_Display_Word(*(s1+i));
  }
}

void LCD_INIT (void)
{
  int  i;
  RW=0;
  EN=0;
  delay_time(d_time);
  delay_time(d_time);
  LCD_COMMAND(0x30);
  LCD_COMMAND(0X01);
  for(i=0;i<10;i++)
    delay_time(d_time);
  LCD_COMMAND(0x3f);
  LCD_COMMAND(0x0c);
  LCD_COMMAND(0x06);
  delay_time(d_time);
  LCD_Clear();
  LCD_Home();
}

void  LCD_ADDRESS(char row, char column)
{
  unsigned char  tmp1;
  int  i;
  tmp1=(row-1)*0x40+(column-1)+0x80;
  for(i=0;i<10;i++)
    delay_time(d_time);
  LCD_COMMAND(tmp1);
  for(i=0;i<10;i++)
    delay_time(d_time);
}

void  showLCD(unsigned char s[])
{
  char  i,j;
  LCD_INIT();
  LCD_Clear();
  LCD_Home();
  for(j=0;j<10;j++)
    delay_time(500);
  LCD_Display_String(String1);
  LCD_ADDRESS(2,1);
  for(i=0;i<16;i++)
  {
    LCD_Display_Word(s[i]);  //顯示一個字元
    for(j=0;j<5;j++)
      delay_time(50000);            //延遲一段時間
  }
}

