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
            cin>>num[j];
        for(j=0,k=1;j<n-1;j++,k++)
        {
            num[j+1]=num[j]+num[j+1]-k;
            ans= num[j+1];
        }
        if(ans %2 == 0)
            cout<<"LOSE\n";
        else
            cout<<"WIN\n";
    }
    return 0;
    
}

