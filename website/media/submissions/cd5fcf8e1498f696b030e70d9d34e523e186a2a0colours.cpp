#include<iostream>
using namespace std;
int main()
{
int a;
cin>>a;
while(a-->0)
{
long  x,y;
cin>>x>>y;

unsigned long long int ans=0;
if(y>x)
{
long p;p=x;
x=y;
y=p;
}
if(x==y) ans=0;

else if(x%2==0)

ans=x+y;
else if(x%2==1)
ans=x-y;
cout<<ans<<endl;
}
}

