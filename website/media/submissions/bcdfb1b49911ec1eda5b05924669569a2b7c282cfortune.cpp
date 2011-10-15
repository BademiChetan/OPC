#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t;
    long long int n,k,a,b;
    cin>>t;
    while(t--)
    {
              
              cin>>n>>k;
              a=pow(2,n);
              b=pow(2,a);
              cout<<b%k<<endl;
    }
    return 0;
}
