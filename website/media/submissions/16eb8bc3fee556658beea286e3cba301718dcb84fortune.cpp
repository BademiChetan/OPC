#include<iostream>
using namespace std;
int main(void)
{
    register int n,a,k,t;
    cin>>t;
    for(;t;t--)
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
    
    
