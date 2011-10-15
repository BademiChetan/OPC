//sg
#include<stdio.h>
//#define verbose
int mod(long n,long k)
{
int c=0,d=1,a,l;
unsigned long test=2147483648;
for( l=15;l>=0;l--)
{
c=c*2;
d=(d*d)%k;
if(test&n)
{
c+=1;
d=(d*4)%k;
}
test/=2;
#ifdef verbose
printf("\nn=%d,k=%d,d=%d,c=%d",n,k,d,c);
#endif
}
return d;
}

 
main()
{
long k[1000],n[1000];
int res[1000];
int t,i;
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%ld%ld",&n[i],&k[i]);
res[i]=mod(n[i],k[i]);
}
for(i=0;i<t;i++)
{
printf("%d\n",res[i]);
}
}

