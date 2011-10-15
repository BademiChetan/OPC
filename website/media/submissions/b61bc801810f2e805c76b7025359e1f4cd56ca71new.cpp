#include<iostream>
using namespace std;
int main()
{
    int t,i=0,j;
    cin>>t;
    long int ans[t],K[t],N[t];
    for(i=0;i<t;i++)
    {

            cin>>N[i]>>K[i];
    }
    for(i=0;i<t;i++)
    {        
            ans[i]=2;
            for(j=0;j<N[i];j++)
            ans[i]*=ans[i];
            ans[i]=ans[i]%K[i];
            
    }

    
    for(i=0;i<t;i++)
    cout<<ans[i]<<endl;
    cin>>j;
    return 0;
    }
            
              
