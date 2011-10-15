#include<graphics.h>
#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<dos.h>
#include<conio.h>
char x[20];
float s=0;
int K=0,ss;
class Colors
{
    private:
    int graphdriver, graphmode;
    palettetype pal;
    public:
    void Init_Graphics()


    {
	initgraph(&graphdriver,&graphmode,"..\\BGI\\");
    }

    void Intro();
    Colors::Colors()
	{
	graphdriver = DETECT;
	Init_Graphics();
	getpalette(&pal);
    }

};

float add(float,float);
int main()
{
	
	K=0;
	int b,i,j,d=0,c=0,a[26],t,k,h,m;
	char str[100],ptr[100],y[100],p;
	Colors Colors;
	Colors.Intro();
	clrscr();
	printf("\n\n\n\t\t\tenter your name:");
	gets(str);
	clrscr();
	printf("\n\n\n\t\t\tenter your partner name:");
	gets(ptr);
	strcpy(x,str);
	strcpy(y,ptr);
	strcat(x," LOVES ");
	strcat(x,y);
	strupr(x);
	strcat(str,"loves");
	strcat(str,ptr);
	strlwr(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]<='l')
		{
			if(str[i]==' ')
			{
				p=str[i+1];
				str[i+1]=str[i];
				str[i]=p;
			}
		}


	}
	for(i='a';i<='z';i++)
	{
		c=0;
		for(j=0;str[j]!='\0';j++)
		{

			if(i==str[j])
			{
				c++;
			}
		}
		if(c>0)
		{
		d++;
		}
	}
	b=strlen(str);
	s=add(b,d);
	clrscr();
	Colors.Intro();
}
void Colors::Intro()
{
    for(int I = 0; I < 63; I++)
    {
	setbkcolor(6);
	setrgbpalette(pal.colors[4],I,I,I);
	delay(75);
    }
		K++;

    for(I = 63; I > 0; I--)
	{
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	setrgbpalette(pal.colors[2],I,I,I);
	setcolor(2);
	if(K<3)
	{
	outtextxy(getmaxx()/2-250,getmaxy()/2-2,"LOVE CALCULATOR");
	}
	delay(100);
	}
	if(K==2)
    {
    printf("\n\n\n\n\t\t\t     ");
    printf("%s\t\t\t\t       ",x);
    printf("\n\n\t\t\t\t%f%\t\t\t   \t\t",s);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t CREATED BY : SOJU\t\t\t\t\t");
    }
    getch();
}

float add(float x,float y)
{
	float s;
	s=(y/x)*100;
	return(s);
}

