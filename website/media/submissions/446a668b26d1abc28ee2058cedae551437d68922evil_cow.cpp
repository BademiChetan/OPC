#include<iostream>
using namespace std;

int main()
{
    long long int money,n,k,ans,j;
    int test,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n>>k;
    money=2;
        ans=n%k;
        for(j=0;j<ans;j++)
            money=money*money;
        cout<<money<<"\n";
    }
    return 0;
}


