#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
    long long t,x,y,ans,num;
    cin>>t;
    while(t--)
    {
              ans=0;
              cin>>x>>y;
              if((x+y)%2)
              {
                         ans=((x-y)>0)?(x-y):(y-x);
              }
              else
              {
                         ans=(x+y);
              }
              cout<<ans<<"\n";
    }
    return 0;
}
