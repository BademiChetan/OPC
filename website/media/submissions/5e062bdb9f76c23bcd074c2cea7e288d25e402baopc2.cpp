#include<iostream>
    using namespace std;

int main()
{
    int t,n,sum,no,term;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        sum = 0;
        for(int j=0;j<n;j++)
        {
            cin>>no;
            sum+=no;
        }
        term = (n*(n-1))/2;
        sum = sum - term;
        if(sum%2==0)
            cout<<"LOSE\n";
        else
            cout<<"WIN\n";
    }
    return 0;
}
