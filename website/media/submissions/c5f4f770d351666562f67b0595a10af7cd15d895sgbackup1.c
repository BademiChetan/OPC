//sg
//sg
#include<stdio.h>
int returnBin(long n,int * a)
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
long lastK(long n,long k)
{
int a[32],c=0,i;
 long d=1;
int p=returnBin(n,a);
long modn=k;
for( i=p;i>=0;i--)
{
c=c*2;
d=(d*d)%modn;
if(a[i]==1)
{
c+=1;
d=(d*4)%modn;
}
}

return d;
}
int main()
{
long k[1000],n[1000];
long res[1000];
int t,i;
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%ld%ld",&n[i],&k[i]);
res[i]=lastK(n[i],k[i]);
}
for(i=0;i<t;i++)
{
printf("%d\n",res[i]);
}
return 0;
}

