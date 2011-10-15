#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t,j;
    unsigned long long n,k,s,a,b;
    cin>>t;
    while(t--)
    {
              s=2;
              cin>>n>>k;
              a=pow(2,n);
              b=pow(s,a);
              j=b%k;
              cout<<j<<endl;
    }
    return 0;
}
