#include<stdio.h>
#define max (y>=x?y:x)
#define check (y>=x?y-x:ch-x+y)
int main()
{
    long long int t,ch,x,y,ans;
    scanf("%lld",&t);
    while(t--)
    {
              scanf("%lld%lld",&x,&y);
              ch=max+1;
              ans=check;
              printf("%lld\n",ans);
    }
    return 0;
}
              
