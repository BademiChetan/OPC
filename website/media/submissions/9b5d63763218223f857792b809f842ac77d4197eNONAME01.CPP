#include<iostream>
using namespace std;
int sqr(int a,int b)
{
int i,s=1;
if(b!=0)
{
for(i=1;i<=b;i++)
{
s=s*a;
}
}
return s;
}
int main()
{
int T,j,N,K,c[1000],r;
cin>>T;
for(j=0;j<T;j++)
{
cin>>N>>K;
r=N%K;
c[j]=sqr(2,sqr(2,r));
}
for(j=0;j<T;j++)
{
cout<<c[j]<<"\n";
}
return 0;
}