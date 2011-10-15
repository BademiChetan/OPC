#include<iostream>
using namespace std;
int main(void)
{
    register int n,a,k,t;
    cin>>t;
    do
    {
        n=2;   
        t--;      
        cin>>a>>k;
        for(;a>0;a--)
        {
                n=n*n;
        }
        cout<<n%k<<endl;
    }while(t);
return 0;
}
    
    
