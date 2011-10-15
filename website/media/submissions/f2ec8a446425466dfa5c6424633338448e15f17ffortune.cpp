#include<iostream>
#include<cmath>
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
unsigned long long int temp;
temp=pow(2,i);
ans=ans<<temp;
ans=(ans+k)%k;
}
cout<<ans<<endl;
}
}
