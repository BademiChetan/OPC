#include<stdio.h>
#include<math.h>
int main()
{
    long long int t,n,k,i,num;
    scanf("%lld",&t);
    while(t--)
    {
              i=1;num=2;
              scanf("%lld%lld",&n,&k);
              while(n--)
              num=pow(num,2);
              printf("%lld\n",num%k);     
    }        
 return 0;
}
