#include<stdio.h>
int main()
{
long long int a[100],ans[100];
long long int n,i,b,c;
scanf("%lld",&n);
a[0]=2;
for(i=1;i<=100;i++)
a[i]=a[i-1]*a[i-1];
for(i=1;i<=n;i++)
{
scanf("%lld",&b);
scanf("%lld",&c);
ans[i]=a[b]%c;
printf("%lld\n",ans[i]);
}
return 0;
} 
