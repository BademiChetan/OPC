#include<iostream>
using namespace std;
int main()
{
int x;
cin>>x;
long long n,k;
while(x-->0)
{
cin>>n>>k;
unsigned long long int ans=2;
for(long long i=0;i<n;i++)
{
ans=ans*ans;
ans=(ans+k)%k;
}
cout<<ans<<endl;
}
}
