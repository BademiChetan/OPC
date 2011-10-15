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
    cout<<((m-1)*pow(2,k)+pow(2,n))/m<<endl;}
    return 0;
}
