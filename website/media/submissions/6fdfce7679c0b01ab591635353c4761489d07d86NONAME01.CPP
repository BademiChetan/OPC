#include<iostream>
using namespace std;
int main()
{
int T,j,i,N,K,c[1000],r;
cin>>T;
for(j=0;j<T;j++)
{
int s=1,h=1;
cin>>N>>K;
r=N%K;
if(r!=0)
{
for(i=0;i<r;i++)
{
s=s*2;
}
for(i=0;i<s;i++)
{
h=h*2;
}
}
else{h=2;}
c[j]=h;
}
for(j=0;j<T;j++)
{
cout<<c[j]<<"\n";
}
return 0;
}