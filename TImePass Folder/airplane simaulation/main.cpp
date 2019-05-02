#include <iostream>
#include<graphics.h>
using namespace std;
void b_circle(int x1,int y1,int r)
{
	int d=3-(2*r);
	int x=0,y=r;
	do
	{
		putpixel(x1+x,y1+y,WHITE);
		putpixel(x1-x,y1+y,WHITE);
		putpixel(x1-x,y1-y,WHITE);
		putpixel(x1+x,y1-y,WHITE);
		putpixel(x1-y,y1+x,WHITE);
		putpixel(x1+y,y1-x,WHITE);
		putpixel(x1-y,y1-x,WHITE);
		putpixel(x1+y,y1+x,WHITE);
		if(d<0)
			d=d+(4*x)+6;
		else
		{
			d=d+4*(x-y)+10;
			y=y-1;
		}
		x=x+1;
	}while(x<y);
}
void dda(float xi,float yi,float xf,float yf)
{
   	float x1=xi,x2=xf,y1=yi,y2=yf,x,y;
   	float dx,dy,length;
   	dx=abs(x2-x1);
   	dy=abs(y2-y1);
   	if(dx>=dy)
   		length=dx;
   	else
   		length=dy;
   	dx=(x2-x1)/length;
   	dy=(y2-y1)/length;
   	x=x1;
   	y=y1;
   	for (int i = 0; i <= length; i++)
    {
        putpixel (x,y,WHITE);
        x += dx;
        y += dy;
    }
}
class point
{
public:
    int x,y,f;
};
class runway
{
public:
    void set_run();
    void show_run();
    void translate_run(int x);
};
class plane
{
    point p[100];
    int n,m;
public:
    void show_plane();
    void set_plane();
    void translate_plane(int x,int y);
    //void rotate_palne(int angle);
};
void plane::set_plane()
{
    p[0].x=75,p[0].y=80,p[0].f=0;     //roof
    p[1].x=129,p[1].y=80,p[1].f=1;
    p[2].x=138,p[2].y=80,p[2].f=0;
    p[3].x=210,p[3].y=80,p[3].f=0;
    p[4].x=240,p[4].y=88,p[4].f=0;   //tip
    p[5].x=240,p[5].y=92,p[5].f=0;
    p[6].x=210,p[6].y=100,p[6].f=0;   //base
    p[7].x=100,p[7].y=100,p[7].f=0;
    p[8].x=75,p[8].y=85,p[8].f=0;       //exhaust
    p[9].x=75,p[9].y=80,p[9].f=0;
    p[10].x=65,p[10].y=40,p[10].f=0;       //tail wing
    p[11].x=80,p[11].y=40,p[11].f=0;
    p[12].x=120,p[12].y=80,p[12].f=1;
    p[13].x=150,p[13].y=90,p[13].f=0;       //flaps
    p[14].x=130,p[14].y=82,p[14].f=0;
    p[15].x=125,p[15].y=75,p[15].f=0;
    p[16].x=130,p[16].y=75,p[16].f=0;
    p[17].x=140,p[17].y=82,p[17].f=0;
    p[18].x=180,p[18].y=90,p[18].f=0;
    p[19].x=150,p[19].y=90,p[19].f=1;
    p[20].x=175,p[20].y=98,p[20].f=0;       //propeller
    p[21].x=175,p[21].y=91,p[21].f=0;
    p[22].x=185,p[22].y=90,p[22].f=0;
    p[23].x=185,p[23].y=99,p[23].f=0;
    p[24].x=175,p[24].y=98,p[24].f=1;
    p[25].x=175,p[25].y=97,p[25].f=0;       //booster
    p[26].x=170,p[26].y=95,p[26].f=0;
    p[27].x=170,p[27].y=94,p[27].f=0;
    p[28].x=175,p[28].y=92,p[28].f=0;
    p[29].x=175,p[29].y=97,p[29].f=1;
    p[30].x=90,p[30].y=85,p[30].f=0;       //horizontal tail fin
    p[31].x=60,p[31].y=77,p[31].f=0;
    p[32].x=57,p[32].y=77,p[32].f=0;
    p[33].x=75,p[33].y=85,p[33].f=0;
    p[34].x=90,p[34].y=85,p[34].f=1;
    p[35].x=200,p[35].y=100,p[35].f=0;        //front wheel holder
    p[36].x=200,p[36].y=105,p[36].f=1;
    p[37].x=205,p[37].y=100,p[37].f=0;
    p[38].x=205,p[38].y=105,p[38].f=1;
    p[39].x=120,p[39].y=100,p[39].f=0;        //back wheel holder
    p[40].x=120,p[40].y=106,p[40].f=1;
    p[41].x=125,p[41].y=100,p[41].f=0;
    p[42].x=125,p[42].y=106,p[42].f=1;
    p[43].x=210,p[43].y=80,p[43].f=0;       //cockpit
    p[44].x=210,p[44].y=90,p[44].f=0;
    p[45].x=240,p[45].y=90,p[45].f=1;
    p[46].x=202.5,p[46].y=110,p[46].f=5;        //front wheel
    p[47].x=123,p[47].y=110,p[47].f=3;        //back wheels
    p[48].x=116,p[48].y=110,p[48].f=3;
    p[49].x=129,p[49].y=110,p[49].f=3;
    n=45,m=49;
}
void plane::show_plane()
{
    int i=0;
    while(i<n)
    {
        if(p[i].f==1)
            i++;
        dda(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
        i++;
    }
    i++;
    while(i<=m)
    {
        b_circle(p[i].x,p[i].y,p[i].f);
        i++;
    }
}
void plane::translate_plane(int x,int y)
{
    for(int i=0;i<=m;i++)
    {
        p[i].x=p[i].x+x;
        p[i].y=p[i].y+y;
    }
}
int main()
{
    plane air1;
    air1.set_plane();
    int i=0,j=0;
    int gm,gd=DETECT;
    initgraph(&gd,&gm,NULL);
    while((100+i)<=400)
    {
        air1.translate_plane(0,1);
        air1.show_plane();
        cleardevice();
        i++;
    }
    getch();
    return 0;
}
