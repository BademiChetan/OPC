#include<iostream>
using namespace std;
unsigned long long int square(int x)
{
         return(x*x);
         }
unsigned long long int power(unsigned long long a,unsigned long long b)
{
         if(b==0)
         return 1;
         if(b%2==0)
         {
         return(square(power(a,b/2)));
         }
         else 
         return(a*power(a,b-1));
}
int main()
{
    int t;
   cin>>t;
    while(t--)
    { unsigned long long int n,k;
  cin>>n>>k;
    unsigned long long int two=2;
    unsigned long long s=power(two,power(2,n));
   cout<<s%k<<endl;
    }
return 0;
}
