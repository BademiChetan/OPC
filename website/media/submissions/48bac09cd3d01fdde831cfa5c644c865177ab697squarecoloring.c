#include<stdio.h>
#define check (y>=x?y-x:n-x+y)
int main()
{
    long long int t,x,y,ans,n=1000001;
    scanf("%lld",&t);
    while(t--)
    {
              scanf("%lld%lld",&x,&y);
              ans=check;
              printf("%lld\n",ans);
    }
    return 0;
}
              
