#include<iostream>
using namespace std;
int r=1,i;
int main(void)
{
    int k,n;
    cin>>k>>n;
    do
    {
                     r=r*k;
                     k=k*r;
                     i++;
                     }
                     while(i<=n);
                     cout<<k;
                     }
