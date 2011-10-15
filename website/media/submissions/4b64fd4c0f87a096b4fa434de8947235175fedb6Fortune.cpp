//iPS

#include<cstdio>

int modexp (int n, int k)
{
    if (n==0)
    {
        return 1;
    }
    int z=modexp(n/2, k);
    if (n%2)
    {
        return (4*z*z) % k;
    }
    else
    {
        return (z*z) % k;
    }
}

int main()
{
    int t;
    int n,k;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",modexp(n,k));
    }
    return 0;
}

