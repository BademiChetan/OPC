#include<stdio.h>
#include<math.h>
int main()
{
int t,s;
long long n,p,k,i;
scanf("%d",&t);
while(t)
{
scanf("%lld%lld",&n,&p);
k=2;
for(i=0;i<n;i++)
k = (long long)(k*k)%(long long)p;
printf("%lld\n",k);
t--;
}
return 0;
}
