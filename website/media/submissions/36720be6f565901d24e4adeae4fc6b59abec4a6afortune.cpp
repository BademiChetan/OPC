#include<iostream>
using namespace std;
int main(void)
{
    int n,k,t,m=0,a;
    cin>>t;
    do
    {
        n=2;   
        m++;      
        cin>>a>>k;
        for(int i=0;i<a;i++)
        {
                
                n=n*n;
        }
        cout<<n%k<<endl;
    }while(m!=t);
return 0;
}
    
    
