//sg
#include<stdio.h>
#define verbose
long long  mod(long n,long k)
{
int c=0,a,l;
long long d=1;
unsigned long test=2147483648u;
for( l=31;l>=0;l--)
{
c=c*2;
d=(d*d)%k;
if(test&n)
{
c+=1;
d=(d*4)%k;
}
test>>=1;
#ifdef verbose
printf("\nn=%d,k=%d,d=%d,c=%d",n,k,d,c);
#endif
}
return d;
}
int main()
{
long k[1000],n[1000];
long long res[1000];
int t,i;
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%ld%ld",&n[i],&k[i]);
res[i]=mod(n[i],k[i]);
}
for(i=0;i<t;i++)
{
printf("%lld\n",res[i]);
}
return 0;
}

