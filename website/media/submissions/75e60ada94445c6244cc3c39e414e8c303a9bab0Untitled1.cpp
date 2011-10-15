#include<iostream>
#include<stdio.h>
using namespace std;

long long t,n,k,a[1009];

int main()
{
    cin>>t;
    int i,j,x,p,y;
    for(i=0;i<t;i++)
    {
                    scanf("%d",&n);
                    scanf("%d",&k);
                    a[i]=1; x=2; p=1;
                    while(x!=1)
                    {
                                    x=x*2;
                                    x=x%k;
                                    p++;
                    }
                    y=1;
                    for(j=0;j<n;j++)
                    {
                                    y=y*2;
                                    y=y%p;
                    }
                    for(j=0;j<y;j++)
                    {
                                    a[i]=a[i]*2;
                                    a[i]=a[i]%k;
                    }
    }
    for(i=0;i<t;i++)
    printf("%d\n",a[i]);
    return 0;
}
