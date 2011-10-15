#include<iostream>
using namespace std;
int main(void)
{
    register int a,t;
    long int k,n;
    cin>>t;
    for(;t>0;t--)
    {
        n=2;        
        cin>>a>>k;
        for(;a>0;a--)
        {
                n=n*n;
        }
        cout<<n%k<<endl;
    }
return 0;
}
    
    
