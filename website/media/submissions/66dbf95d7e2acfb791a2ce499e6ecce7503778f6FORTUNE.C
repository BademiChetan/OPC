#include<stdio.h>
#include<math.h>
void main()
{
int T,j,N,K,c[1000],r;
scanf("%d",&T);
for(j=0;j<T;j++)
{
scanf("%d%d",&N,&K);
r=N%K;
c[j]=pow(2,pow(2,r));
}
for(j=0;j<T;j++)
{
printf("%d\n",c[j]);
}
}
