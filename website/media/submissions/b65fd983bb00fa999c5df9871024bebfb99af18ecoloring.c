#include<stdio.h>
main()
{
int t;
int x,y,mod,ans,temp,op;
scanf("%d",&t);
while(t--)
{
scanf("%d%d",&x,&y);
if(x>y)
{
temp = y;
y=x;
x=temp;
}

mod=y%4;

if(mod==0||mod==1)
{
op=1;
}
else
{
op=-1;
}

if(y==x)
{
ans=0;
}
else if(y%2&&y==x+1)
{
ans=1;
}

else
{
if(x%2==0)
ans=y+op*x;

else
{
if(y%2)
ans=y-1+op*(x-1);
else
ans=y+1+op*(x-1);
}
}
printf("%d\n",ans);
}
return 0;
}
