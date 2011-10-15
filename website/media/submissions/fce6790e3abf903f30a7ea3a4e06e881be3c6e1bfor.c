#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,b,i,c;

scanf("%d",&n);
int *a = malloc (sizeof (int) * n);
int *ans = malloc (sizeof (int) * n);
a[0]=2;
for(i=1;i<=100;i++)
a[i]=a[i-1]*a[i-1];
for(i=1;i<=n;i++)
{
scanf("%d",&b);
scanf("%d",&c);
ans[i]=a[b]%c;

printf("%d\n",ans[i]);
}
return 0;
}
