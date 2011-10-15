#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;            
            sum = sum + x;
        }        
        int t=n*(n-1)/2;
        if((sum-t)%2==0)
        {
            printf("LOSE\n");
        }       
        else printf("WINS\n");
    }
    return 0;
}
