#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,i, n,k,arr[1000],a,b,j;
scanf("%d",&t);
if((t>=1)&&(t<=1000))
{
for(i=1;i<=t;i++)
{
scanf("%d %d",&n,&k);
if(k%2!=0)
{
a=pow(2,(2*n));
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
