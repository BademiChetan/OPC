//sg
//sg
#include<stdio.h>
#include<cmath>
int returnBin(long long n,int * a)
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
void lastK(long long n,long long k)
{
int a[32],c=0,i;
long long d=1;
long long t1=pow(2,n);
int p=returnBin(t1,a);
long long modn=k;
//long t1=pow(2,n);
//long long a1=pow(2,t1);

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
printf("%lld",d);
}
int main()
{
long long j,*n,*k;
int t,i;
scanf("%d",&t);
n=new long long[t];
k=new long long[t];
for( i=0;i<t;i++)
{
scanf("%lld%lld",&n[i],&k[i]);
}
for(int i=0;i<t;i++)
{
lastK(n[i],k[i]);
printf("\n");
}
return 0;
} 
