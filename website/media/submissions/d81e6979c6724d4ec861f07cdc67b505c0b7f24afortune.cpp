#include<stdio.h>
int main()
{
    long long int t,n,k,init,num;
    scanf("%lld",&t);
    while(t--)
    {
              init=1;
              num=2;
              scanf("%lld  %lld",&n,&k);
              while(n--)
              {
                        num=num<<init;
                        init=init*2;
              }
              printf("%lld",(num%k));     
              }         
 return 0;
}
