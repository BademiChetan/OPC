#include<stdio.h>
main()
{
int i,j,T,N,t=0,a,b;
char ar[12][12];

scanf("%d",&T);
scanf("%d",&N);
while(T)
{
for(i=0;i<N;i++)
{
scanf("%d",ar[i][0]);
scanf("%d",ar[i][1]);
}
}
for(i=0;i<N;i++)
{
a=ar[i][0];
b=ar[i][1];
t=t+1;
if((a+b-t)%2)
printf("WIN");
else
printf("LOSE");
}
}