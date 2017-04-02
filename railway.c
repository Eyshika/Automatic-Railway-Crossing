#include <REGx51.H>
sbit ir1=P1^0;
sbit ir2=P1^1;
sbit led=P2^4;
void delay(unsigned int);
void delay(unsigned int msec)
{
	unsigned int i;
	for(i=0;i<msec;i++)
	{
	 TMOD=0x01;
	 TH0=0xFC;
	 TL0=0x00;
	 TR0=1;
	 while(TF0==0);
	 TF0=0;
	 TR0=0;
	}
}
void main()
{
 int step_array[13]={0x01,0x03,0x02,0x06,0x04,0x0C,0x08,0x09,0x01,0x03,0x02,0x06,0x04};
 unsigned int k=0; 
  P2=0x00;
  P3=0x00;
  while(1)
 {
  start:
 led=1;
 delay(200);
 led=0;
 delay(200);
   	   
   if(ir1==1 || ir1==0&&ir2==1)
    {
	if(k==0)
   {	  
   for(k=0;k<=12;k++)
   {
	P3=step_array[k];
	P2=step_array[k];
	delay(50);
	while(k==12)
	{
	wait:	 
 if(ir1==0&&ir2==0)
  {
  	for(k=12;k>=0;k--)
   {
   P3=step_array[k];
   P2=step_array[k];
   delay(50);
	if(k==0)
	{ goto start;
	}
  }
   }
   
   else goto wait;
   }
 }
 }
 }
 }
 }
  
 

  

