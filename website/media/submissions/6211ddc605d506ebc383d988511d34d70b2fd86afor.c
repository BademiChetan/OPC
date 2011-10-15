#include<stdio.h>
int main()
{
int a[100],ans[100];
int n,i,b,c;
scanf("%d",&n);
a[0]=2;
for(i=1;i<=100;i++)
a[i]=a[i-1]*a[i-1];
for(i=1;i<=n;i++)
{
scanf("%d",&b);
scanf("%d",&c);
ans[i]=a[b]%c;
}
for(i=1;i<=n;i++)
printf("%d\n",ans[i]);
return 0;
} 
