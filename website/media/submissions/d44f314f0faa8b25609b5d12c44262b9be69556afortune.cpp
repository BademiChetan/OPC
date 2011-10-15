#include<iostream>
using namespace std;
int r=1;
int main(void)
{
    int k,n;
    cin>>k>>n;
    for(int i=0;i<=n;i++)
    {
                     r=r*k;
                     k=r;
                     }
                     cout<<k;
                     }
