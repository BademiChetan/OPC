#include<stdio.h>
int out(int, int);
int main()
{
int t,n[20],k[20],i=0;
scanf("%d", &t);
while(i<t)
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
p*=p;
i++;
}
printf("%d\n",p%m);
return 0;
}

