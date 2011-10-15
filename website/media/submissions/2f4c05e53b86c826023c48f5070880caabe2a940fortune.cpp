#include<iostream>
#include<math.h>
using namespace std;
int main(void)
{
    register int a,t;
    long int k;
    cin>>t;
    for(;t>0;t--)
    {        
        cin>>a>>k;
        int ans;
        ans=pow(2,(pow(2,a)));        
        cout<<ans%k<<endl;
    }
return 0;
}
    
    
