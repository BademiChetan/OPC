//iPS

#include<cstdio>

int main()
{
    int t;
    int n,k;
    int temp;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&k);
        temp=2;
        for (int i=1;i<=n;i++)
        {
            temp=(temp*temp)%k;
            if (temp==1)
            {
                break;
            }
        }
        printf("%d\n",temp);
    }
    return 0;
}

/*
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
        return (2*z) % k;
    }
    else
    {
        return (z*z) % k;
    }
}
*/
