#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    long long n,k,a,b;
    scanf("%d",&t);
    while(t--)
    {
              
              scanf("%lld %lld",&n,&k);
              a=pow(2,n);
              b=pow(2,a);
              printf("%lld\n",b%k);
    }
    return 0;
}
