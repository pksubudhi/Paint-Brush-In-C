#include<graphics.h>
#include<dos.h>
#include<alloc.h>
#include "msdrv.h"

char st[20];
int col=5;
union REGS i,o;

main()
{
	int gd=DETECT,gm,button,x,y,maxx,maxy,prevx,prevy;
	int i,j;
	char *p;
	initgraph(&gd,&gm,"f:\\tc");

	maxx=getmaxx();
	maxy=getmaxy();
	for(j=0;j<=13;j++)
	{
		for(i=1;i<=28;i++)
		{
			setcolor(j+1);
			line(600,10+i+(j*30),630,10+i+(j*30));
		}
	}
	rectangle(0,0,maxx-50,maxy-50);
	setviewport(1,1,maxx-1-50,maxy-50-1,1);

	initmouse();
	restrictmouseptr(1,1,maxx-1,maxy-1);
	showmouseptr();
	while(!kbhit())
	{
		getmousepos(&button,&x,&y);

		if((button&1)==1)
		{

			if(x>600)
			{
				col=((y+19)/30);
			}
			hidemouseptr();
			prevx=x;
			prevy=y;

			while((button&1)==1)
			{
				setcolor(col);
				setlinestyle(0,5,20);
				line(prevx,prevy,x,y);

				prevx=x;
				prevy=y;
				getmousepos(&button,&x,&y);
			}

			showmouseptr();
		}
	}
}
