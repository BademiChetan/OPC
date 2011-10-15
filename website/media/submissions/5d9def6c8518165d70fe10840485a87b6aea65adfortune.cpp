#include<iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);

// Variables

    int t;
    cin>>t;
    int n,k,i,r;
    while(t--)
    {
         cin>>n>>k;
         r=2;
         for(i=1;i<=n;i++)
         {
                   r=(r*(r%k))%k;
         }
         
         cout<<r<<endl;

    }

    return 0;
}
