#include<stdio.h>

long int totient(long int k)
{
    long int k2=k,i;
    for(i=3;i*i<k2;i++)
    {
        if(k%i==0)
        {
            k-=k/i;
            while(k2%i==0) k2/=i;
        }
    }
    if(k2>1)
    {
        k-=k/k2;
    }
    return k;
}

long long int power(long int base, long long int exp, long int rem)
{
long long int result = 1;
while (exp)
{
if (exp & 1)
{result = (result*base)%rem;}
exp >>= 1;
base = (base*base)%rem;
}
return result;
}

int main()
{
    long int t; scanf("%ld",&t);
    for(;t>0;t--)
    {
        long int n,k,r;
	long long int c;
        scanf("%ld",&n);scanf("%ld",&k);
        long int phi=totient(k),l=0;
        long int j=phi;
        while(j%2==0) {j/=2;l++;}
        long int x=(n-l)%totient(j);
        c=power(2,(long long int)x+l,phi);
        r=power(2,c,k);
        printf("%ld\n",r);
    }
return 0;
}
