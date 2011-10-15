#include<iostream>
using namespace std;
int main()
{
    int t,n,a[100];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        long int sum =0;
        int num;
        for(int j=0;j<n;j++)
        {
           cin>>num;
           sum+=num;
        }
        a[i]=(sum - (n*(n-1)/2))%2;
    }
    for(int i=0;i<t;i++)
    {
        if(a[i])
        cout<<"WIN"<<endl;
        else
        cout<<"LOSE"<<endl;
    }
return 0;
}

        
