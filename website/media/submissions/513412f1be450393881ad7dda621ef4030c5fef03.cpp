#include<iostream>
using namespace std;
main()
{
    long long int n,k,j;
    int t,size,sum,num;
    bool bin[100];
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        j=0;
        n++;
        while(n>0)
        {
            bin[j++]=n%2;
            n=n/2;
        }
        size=j;
        num=2;
        sum=0;
        for(j=j-3;j>=0;j--)
        {
            num=num*num;
            if(bin[j])
                sum+=num%k;
        }
        sum=sum%k;
        cout<<sum<<endl;
    }
}
