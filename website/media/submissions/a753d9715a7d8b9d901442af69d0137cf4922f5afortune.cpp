#include<iostream>
using namespace std;
long long mod_exp(long long b,long long e,long long k)
{
    long long r=1;
    for(;e;e>>=1)
    {
        if(e&1)
            r=(r*b)%k;
        b=(b*b)%k;
    }
    return r;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        cout<<mod_exp(2,mod_exp(2,n,k),k)<<endl;
    }
    return 0;
}
