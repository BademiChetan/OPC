#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long mod_exp(long long b,long long e,long long k)
{
    unsigned long long r=1;
    for(;e;e>>=1)
    {
        if(e&1)
            r=(r*b)%k;
        b=(b*b)%k;
    }
    return r;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        scanf("%lld %lld",&n,&k);
        if(k!=1)
        printf("%llu\n",mod_exp(2,mod_exp(2,n,k-1),k));
        else 
        printf("0\n");
    }
    return 0;
}
