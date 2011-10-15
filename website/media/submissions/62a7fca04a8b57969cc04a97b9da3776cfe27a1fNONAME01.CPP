#include<iostream>
using namespace std;
int sqr(int a,int b)
{
int i=1,s=1;
if(b!=0)
{
while(i<=b)
{
s=s*a;
i++;
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