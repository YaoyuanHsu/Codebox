 #include<reg51.h>
 #include<stdio.h>

 sbit start = P0^0; sbit bin = P3^2; sbit check = P0^1;

 void delay(unsigned int time, unsigned int i, unsigned int j)
 {
     for(i = 0; i < time;i++)
        for(j = 0;j < 17;j++);
 }

void voice(unsigned int time, unsigned int count)
{
     for( ; count<=500 ; count++){
        bin = 1;
        delay(time);
        bin = 0;
        delay(time);
     }
}

 void main()
 {
	while(1){
        check = start;
        while((start ^ check) == 0)
            P2 = 0x2B;
        P2 = 0x33;
        delay(30000, 0, 0);
 //////////////////////9sec/////////////////////////////////
        P2 = 0x1D;
        P1 = 0x90;
        delay(9000, 0, 0);
        voice(1, 0);    //9sec
        P1 = 0x80;
        delay(9000, 0, 0);
        voice(1, 0);    //8sec
        P1 = 0xF8;
        delay(9000, 0, 0);
        voice(1, 0);    //7sec
        P1 = 0x82;
        delay(9000, 0, 0);
        voice(1, 0);    //6sec
        P1 = 0x92;
        delay(9000, 0, 0);
        voice(1, 0);    //5sec
        P1 = 0x99;
        delay(9000, 0, 0);
        voice(1, 0);    //4sec
        P1 = 0xB0;
        delay(1000, 0, 0);
        voice(1, 0);
        delay(7000, 0, 0);
        voice(1, 0);    //3sec
        P1 = 0xA4;
        delay(1000, 0, 0);
        voice(1, 0);
        delay(7000, 0, 0);
        voice(1, 0);    //2sec
        P1 = 0xF9;
        delay(1000, 0, 0);
        voice(1, 0);
        delay(7000, 0, 0);
        voice(1, 0);    //1sec
        P1 = 0xFF;
	}
 }

//Code for 8051 traffic light control
