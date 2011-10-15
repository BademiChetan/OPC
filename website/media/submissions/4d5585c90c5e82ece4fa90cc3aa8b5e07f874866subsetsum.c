#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
int ar[100],t,j,i,k,n,a,b,c=2;
scanf("%d\n",&t);
if(t>=1 && t<=1000)
{
for(i=0;i<t;i++)
{
scanf("%d %d",&n,&k);
a=(n*(n+1)/2);
b=(int)a/k;
if(b>0)
{
ar[i]=2<<b-1;
}
else
{
ar[i]=1;
}

}
}
for(i=0;i<t;i++)
{
printf("%d\n",ar[i]);
}
}
