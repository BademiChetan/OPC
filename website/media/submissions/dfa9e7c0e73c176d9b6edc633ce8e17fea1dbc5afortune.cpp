#include<iostream>
using namespace std;
int main()
{
    int t,j;
    unsigned long long n,k,s;
    cin>>t;
    while(t--)
    {
              s=2;
              cin>>n>>k;
              for(int i=1;i<=n;i++)
              s=(s*s);
              j=s%k;
              cout<<j<<endl;
    }
    return 0;
}
