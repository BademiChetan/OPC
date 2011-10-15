#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    
    int cost=0;
    int n,k,T,i;
    cout<<"\nEnter the number of test cases:";
    cin>>T;
    if(T<1 || T>1000)
   
    exit(1);

    
    for(i=1;i<=T;i++)
    {
    cout<<"\nEnter the number of days:";
    cin>>n;
    cout<<"\nEnter k:";
    cin>>k;
    if(k%2==0)
    {
    exit(0);
}
    
    
                     cost=pow(2,pow(2,n));
                     
                     
                     
                     cout<<(cost % k);
                     }
                     return 0;
                     }
                     
