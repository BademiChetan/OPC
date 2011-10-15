#include<stdio.h>
int main()
{
    long long int t,x,y,ans,n=1000001;
    scanf("%lld",&t);
    while(t--)
    {
              scanf("%lld%lld",&x,&y);
              if(y>=x)
              ans=y-x;
              else
              ans=n+y-x;
              printf("%lld\n",ans);
    }
    return 0;
}
              
