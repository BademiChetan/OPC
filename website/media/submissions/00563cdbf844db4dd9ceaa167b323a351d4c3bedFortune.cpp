//iPS

#include<cstdio>

long long int modexp (long long int n, long long int k)
{
    if (n==0)
    {
        return 1;
    }
    long long int z=modexp(n/2, k);
    if (n%2)
    {
        z=(z*z) % k;
        return (4*z) % k;
    }
    else
    {
        return (z*z) % k;
    }
}

int main()
{
    long long int t;
    long long int n,k;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld%lld",&n,&k);
        printf("%lld\n",modexp(n,k));
    }
    return 0;
}

