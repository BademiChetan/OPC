#include<iostream>
using namespace std;
int main()
{
    int i,j,t,n,k,ans;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int num[n];
        for(j=0;j<n;j++)
        {
            cin>>num[j];
        }
        if(n%2 == 0)
        for(j=0,k=1;j<n;j+=2,k++)
        {
            ans = num[j]+num[j+1]-k;
        }
        else
            ans= num[n-1];
        if(ans %2 == 0)
            cout<<"LOSE\n";
        else
            cout<<"WIN\n";
    }
    return 0;
    
}

