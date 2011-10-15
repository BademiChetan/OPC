#include<iostream>
    using namespace std;

int mpow(int exponent, int modulus)
{
    long long base = 2;
    while (exponent > 0)
    {
        exponent--;
        base = (base * base) % modulus;
    }
    return base;
}


int main()
{
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        cout<<mpow(n,k)<<"\n";
    }
    return 0;
}
