#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,i;
int n,k,arr[1000];
int a,b,j;
scanf("%d",&t);
if((t>=1)&&(t<=1000))
{
for(i=1;i<=t;i++)
{
scanf("%d %d",&n,&k);
if(k%2!=0)
{
a=1;
for(j=1;j<=n;j++)
{
a=4*a;
}
b=a%k;
arr[i]=b;
}
}
}
for(i=1;i<=t;i++)
{
printf("%d\n",arr[i]);
}
return 0;
}
