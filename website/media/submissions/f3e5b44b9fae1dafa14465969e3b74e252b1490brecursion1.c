#include<stdio.h>
#include<conio.h>
int fact(int);
int main()
{
int a,c;
printf("enter any number:");
scanf("%d",&a);
c=fact(a);
printf("factorial value:%d",c);
getch();
}
int fact(int x)
{
int f;
if(x==1)
{
return(1);
}
else
{
f=x*fact(x-1);
return(f);
}
}
