#include<stdio.h>
int out(int, int);
int main()
{
int t,n[2],k[2],i=0;
scanf("%d",&t);
while(i<2)
{
scanf("%d%d",&n[i],&k[i]);
i++;
}
i=0;
while(i<t)
{
out(n[i],k[i]);
i++;
}
return 0;
}
int out(int n,int m)
{
int p=2,i=1;
while(i<=n)
{
p=p*p;
i++;
}
p=p%m;
printf("%d\n",p);
return 0;
}