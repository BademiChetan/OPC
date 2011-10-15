#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int n,A,b,i,j;
int *a;
int t;
scanf("%d",&n);
a=malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
t=2;
scanf("%d %d",&A,&b);
for(j=0;j<A;j++)
t=t*t;
a[i]=t%b;
}
for(i=0;i<n;i++)
printf("%d\n",a[i]);
return 0;
}
