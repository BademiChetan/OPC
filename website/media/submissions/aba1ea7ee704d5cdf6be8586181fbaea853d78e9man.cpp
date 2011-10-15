#include<iostream>
using namespace std;
int main()
{
    int n,i,t,j,c,temp;
    unsigned long k;
    cin>>t;
    int a[t];
    for(i=1;i<=t;i++)
    {
    cin>>n>>k;
    a[i]=temp=0;
    for(j=1;j<=n;j++)
    { 
    temp=temp+j;
    for(c=j+1;c<=n;c++)
    {
    if((j+c)%k==0)
    a[i]++;
    }
    if(j%k==0)
    a[i]++;
    
    }
        if(temp%k==0)
        a[i]=a[i]+1;

    }
        for(i=1;i<=t;i++)
        cout<<a[i]+1<<endl;
       
    return 0;
    
    } 
