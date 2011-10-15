#include<stdio.h>
#include<math.h>
int main()
{
int t,s;
long long n,p;
scanf("%d",&t);
while(t)
{
scanf("%lld%lld",&n,&p);
printf("%lld\n",(long long)(pow(2,pow(2,n)))%(long long)p);
t--;
}
return 0;
}
