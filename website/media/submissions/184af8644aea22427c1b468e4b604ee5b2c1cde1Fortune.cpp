#include<iostream>
using namespace std;
int main(){
int T,n[1000],i,k[1000],a,j;
cin>>T;
for(i=0;i<T;i++)
{
cin>>n[i];
cin>>k[i];
}

for(j=0;j<T;j++)
{
a=2;
for(i=0;i<n[j];i++)
{a=a*a;}
cout<<a%k[j]<<endl;
}
}