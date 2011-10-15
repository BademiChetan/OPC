#include<iostream>
using namespace std;
main()
{
    long long int n,k,j;
    int t,x;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        x=2;
        for(j=1;j<=n;j++)
        {
            x=x*2;
            x=x%k;
        }
        cout<<x<<endl;
    }
}
