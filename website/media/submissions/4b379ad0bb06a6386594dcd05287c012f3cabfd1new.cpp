#include<iostream>
using namespace std;
int main()
{
    int t,i=0,N,j;
    cin>>t;
    long int ans[t],K;
    for(i=0;i<t;i++)
    {
            cin>>N>>K;
            j=0;
            ans[i]=2;
            while(j++<N)
            ans[i]*=ans[i];
            ans[i]=ans[i]%K;
            
    }
    
    for(i=0;i<t;i++)
    cout<<ans[i]<<endl;
    return 0;
    }
            
              
