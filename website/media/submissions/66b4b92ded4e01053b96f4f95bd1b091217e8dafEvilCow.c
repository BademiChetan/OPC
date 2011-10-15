#include<stdio.h>

int totient(int k)
{
    int k2=k,i;
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

int power(int base, int exp, int rem)
{
int result = 1;
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
    int t; scanf("%d",&t);
    for(;t>0;t--)
    {
        int n,k,c,r;
        scanf("%d",&n);scanf("%d",&k);
        int phi=totient(k),l=0;
        int j=phi;
        while(j%2==0) {j/=2;l++;}
        int x=(n-l)%totient(j);
        c=power(2,x+l,phi);
        r=power(2,c,k);
        printf("%d\n",r);
    }
}
