//sg
//sg
#include<stdio.h>
int returnBin(int n,int * a)
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
long long firstK(long long n, long long k)
{
 long double dummy;
     /*
float * ptr=new float(10.0);
long double ans,ans1,ans2,final;
ans=(long double)n*log10((long double)n);
cout<<setprecision(19)<<ans;
final=modf(ans,ptr);
ans2=pow((long double)10.0,(long double)final);//this will be the imp part,rest will be only zeroes ct with this
cout<<setprecision(19)<<"\n"<<final<<"\n";
long long firstk=(long long)floor(pow(10.0,(double)(ans2+k-1)));//10 to power something cannot be zero,so k-1
*/
return (long long)floor(pow((long double)10.0, modf((long double)n*log10((long double)n), &dummy) + k - 1)) ;

}
void lastK(long long n,long long k,long long * lk)
{
int a[32],c=0,i;
long long d=1;
int p=returnBin(n,a);
long long modn=k;
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
for( i=k-1;i>=0;i--)
{
     lk[i]=d%10;
     d/=10;
}

}
main()
{
      long long j,*n,*k,**lk;
int t,i;
scanf("%lld",&t);
n=new long long[t];
k=new long long[t];
lk=new long long int* [t];
for( i=0;i<t;i++)
lk[i]=new long long[9];
for( i=0;i<t;i++)
{
scanf("%lld%lld",&n[i],&k[i]);
}
for(int i=0;i<t;i++)
{
lastK(n[i],k[i],lk[i]);
for( j=0;j<k[i];j++)
{
        printf("%lld",lk[i][j]);
}
printf("\n");
}
}
