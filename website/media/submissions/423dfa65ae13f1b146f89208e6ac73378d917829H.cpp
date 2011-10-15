#include<iostream>
#include<math.h>

using namespace std;

int n,m,k,t,i;

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {cin>>n>>m;
    k=n/m;
    cout<<pow(2,k)<<endl;}
    return 0;
}
