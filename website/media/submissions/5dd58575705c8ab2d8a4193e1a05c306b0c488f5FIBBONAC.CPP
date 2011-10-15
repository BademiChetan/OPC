#include<stdio.h>
#include<conio.h>
void main()
{
int n,a=0,b=1,c,i;
clrscr();
printf("enter the limit of the series");
scanf("%d",&n);
if(n==0)
printf("%d\n",a);
else
printf("%d\n%d\n",a,b);
for(i=2;i<=n;i++)
{
c=a+b;
printf("%d\n",c);
a=b;
b=c;
}
getch();
}