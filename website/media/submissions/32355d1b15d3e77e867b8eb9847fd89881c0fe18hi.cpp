#include<iostream>
#include<cmath>
using namespace std;
int main()
{long double t,n;
long long int l,k;
cin>>t;
while(t--)
{
cin>>n>>k;

l=(long long int)pow(2,n/2);
l%=k;
l=(long long int)pow(2,(double)l);
l%=k;
l=(long long int)pow(2,(double)l);
l%=k;
cout<<l<<"\n";
}

}
