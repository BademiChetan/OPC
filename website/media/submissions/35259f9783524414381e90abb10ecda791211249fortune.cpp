#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
unsigned long long sq(unsigned long long n)
{
         return n*n;
}
main()
{
      int t;
      cin>>t;
      while(t--)
      {
                unsigned long long n,k;
                cin>>n>>k;
                int no=n;
                n=2;
                while(no--)
                {
                          n=sq(n);
                }
                //cout<<n<<"\n";
                cout<<n%k<<"\n";
      }
}
