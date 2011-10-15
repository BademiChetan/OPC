#include<stdio.h>
int main()
{
    long long int t,ch,x,y,ans;
    scanf("%lld",&t);
    while(t--)
    {
              scanf("%lld%lld",&x,&y);
              if(y>=x)
              ch=y+1;
              else
              ch=x+1;
              if(y>=x)
              ans=y-x;
              else
              ans=ch-x+y;
              printf("%lld\n",ans);
    }
    return 0;
}
              
