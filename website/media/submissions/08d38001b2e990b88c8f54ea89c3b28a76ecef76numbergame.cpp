#include<iostream>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        int arr[n];int sum=0;
        for(int y=0;y<n;y++)
        {
            cin>>arr[y];
            sum=sum+arr[y];
        }
        sum=sum-((n*(n-1))/2);
        if((sum%2)==0)
        cout<<"LOSE"<<endl;
        else
        cout<<"WIN"<<endl;
    }
    return 0;
}        
                
        
