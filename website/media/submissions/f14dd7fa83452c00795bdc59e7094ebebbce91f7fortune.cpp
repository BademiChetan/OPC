#include<iostream>
using namespace std;

int main(void)
{
    int exp(int,int);
    register int a,t;
    long int k;
    cin>>t;
    for(;t>0;t--)
    {        
        cin>>a>>k;
        int ans;
        ans=exp(2,exp(2,a));        
        cout<<ans%k<<endl;
    }
return 0;
}

int	exp(int	base,int exponent)
{
    int	value;
    if (exponent == 0)
    {
        value = 1;
    }
    else
    {
        value = exp(base * base,exponent/2);
        if (exponent & 1)
        {
            value *= base;
        }
    }
    return value;
}
