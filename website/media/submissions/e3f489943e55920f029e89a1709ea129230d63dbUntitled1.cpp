#include<iostream>
#include<stdio.h>
using namespace std;

long long t,n,k,a[1000];

int main()
{
    cin>>t;
    int i,j;
    for(i=0;i<t;i++)
    {
                    scanf("%d",n);
                    scanf("%d",k);
                    a[i]=2;
                    for(j=0;j<n;j++)
                    {
                                    a[i]=a[i]*2;
                                    a[i]=a[i]%k;
                    }
    }
    for(i=0;i<t;i++)
    printf("%d",a[i]);
    return 0;
}
