#include<iostream>

using namespace std;

int main()
{
    int t,i;
    long int n,k,j;
    long money,ans;

    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        cin>>k;
        money=2;
        for(j=0;j<n;j++)
        {
            money*=money;
        }
        ans=money%k;
        cout<<ans<<endl;
    }

    return 0;

}
