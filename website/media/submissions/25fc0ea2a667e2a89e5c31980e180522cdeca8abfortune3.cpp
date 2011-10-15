#include<stdio.h>
int main()
{
    long long int t,n,k;
    scanf("%lld",&t);
    while(t--)
    {
              scanf("%lld%lld",&n,&k);
              if(n==1)
              printf("%lld\n",(4%k));
              else if(n%2==0)
              printf("%lld\n",(16%k));
              else
              printf("%lld\n",(256%k));
              }
              return 0;
              }
