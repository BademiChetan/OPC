#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long money,n,k,ans,j;
    int test,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n>>k;
        ans=n%k;
            money=pow(2,pow(2,ans));
        cout<<money<<"\n";
    }
    return 0;
}


