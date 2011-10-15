#include<iostream>
using namespace std;

char set[30];
int n,r,K,count=0;
char com[10];

void comb(int m,int k)
{
    if(k==r)
    {
        int sum=0;
        for(int i=0; i<r; i++)
        {
            sum+=com[i];
        }
        if(sum%K==0) count++;
    }
    else
    {
        for(int i=m; i<=((n-r)+k); i++)
        {
            com[k]=set[i];
            comb(i+1,k+1);
        }
    }
}

main()
{

    int i;                   // K is the prime no.
    cout<<"enter the no of elements: " ;
    cin>>n;
    for(i=0;i<n;i++)set[i]=i+1;
    cout<<"\nNow enter the no. K:";
    cin>>K;
    for(i=0;i<=n;i++)
    {
        r=i;
        comb(0,0);
    }
    cout<<"\n"<<count;
}
