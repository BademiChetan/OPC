#include<iostream>
using namespace std;

int main(void)
{
    int exp(long int,long int);
    register int t;
    long int k;
    cin>>t;
     long int temp,a;
    for(;t>0;t--)
    {        
        cin>>a>>k;
        temp=exp(2,a);
        
        cout<<exp(2,temp)%k<<endl;
    }
return 0;
}

unsigned long int	exp(long int	base,long int exponent)
{
    unsigned long int	value;
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
/*
n=2;
cin>>a>>k;
for(;a;a--)
{
           n=n*n;
}*/
