//sg
//sg
#include<stdio.h>
#include<cmath>
int returnBin( long n,int * a)
{
int i=0;
while(n)
{
if(n&1)
{
a[i]=1;
}
else
a[i]=0;
i++;
n/=2;
}
return i-1;
}
void lastK(long n,long k)
{
int a[32],c=0,i;
long d=1;
long t1=pow(2,n);
int p=returnBin(t1,a);
long modn=k;
for( i=p;i>=0;i--)
{
c=c*2;
d=(d*d)%modn;
if(a[i]==1)
{
c+=1;
d=(d*2)%modn;
}
}
printf("%ld",d);
}
int main()
{
long j,n[1000],k[1000];
int t,i;
scanf("%d",&t);
for( i=0;i<t;i++)
{
scanf("%ld%ld",&n[i],&k[i]);
}
for(int i=0;i<t;i++)
{
lastK(n[i],k[i]);
printf("\n");
}
return 0;
} 
