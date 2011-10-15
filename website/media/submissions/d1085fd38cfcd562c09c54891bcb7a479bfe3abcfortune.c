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
printf("%d\n",(int)(pow(2,pow(2,n)))%(p));
t--;
}
return 0;
}
