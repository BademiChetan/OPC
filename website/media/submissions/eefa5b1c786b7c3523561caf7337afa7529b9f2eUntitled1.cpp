#include<iostream>
#include<stdio.h>
using namespace std;

long long t,n,k,a[1009];

int main()
{
    cin>>t;
    int i,j;
    for(i=0;i<t;i++)
    {
                    cin>>n>>k;
                    a[i]=2;
                    for(j=0;j<n;j++)
                    {
                                    a[i]=a[i]*a[i];
                                    a[i]=a[i]%k;
                    }
    }
    for(i=0;i<t;i++)
    cout<<a[i];
    return 0;
}
