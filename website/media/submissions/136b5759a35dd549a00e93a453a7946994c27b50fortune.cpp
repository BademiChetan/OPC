#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void solve();

int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
     solve();
    }
    return 0;
}

void solve()
{
     int n,a;
     long sum=0;
     cin>>n;
     for(int i=0;i<n;i++)
     {
            cin>>a;
            sum+=a; 
     }
     sum=sum-n*(n+1)/2;
     if(sum%2)
     {
              cout<<"WIN\n";
     }
     else
     {
              cout<<"LOSE\n";
     }
}
