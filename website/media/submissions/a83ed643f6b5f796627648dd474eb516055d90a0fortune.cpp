#include<iostream>
#define square(x) (x*x)
using namespace std;
unsigned long long int power(unsigned long long a,unsigned long long b)
{
         if(b==1)
         return a;
         if(b%2==0)
         {unsigned long long x=power(a,b/2);
         return(square(x));
         }
         else 
         return(a*power(a,b-1));
}
int main()
{
    int t;
   cin>>t;
    while(t--)
    { int n,k;
  cin>>n>>k;
    unsigned long long int two=2;
    unsigned long long k2=power(two,n);
    unsigned long long s=power(two,k2);
   cout<<s%k<<endl;
    }
return 0;
}
