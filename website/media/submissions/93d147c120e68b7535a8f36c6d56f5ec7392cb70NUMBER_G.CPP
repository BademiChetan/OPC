#include<iostream>
#include<math.h>
using namespace std;
int main()
{
clrscr();
int T,j,N,K,c[1000],r;
cin>>T;
for(j=0;j<T;j++)
{
cin>>N>>K;
r=N%K;
c[j]=pow(2,pow(2,r));
}
for(j=0;j<T;j++)
{
cout<<c[j]<<"\n";
}
return 0;
}
