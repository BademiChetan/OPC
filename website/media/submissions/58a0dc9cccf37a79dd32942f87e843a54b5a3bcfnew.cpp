#include<iostream>
using namespace std;
int main()
{
    int t,i=0,N,j;
    cin>>t;
    long int ans[t],K;
    while(i<t)
    {
            cin>>N>>K;
            j=0;
            ans[i]=2;
            while(j++<N)
            ans[i]*=ans[i];
            ans[i]=ans[i]%K;
            i++;
    }
    i=0;
    while(i<t)
    {
              
              cout<<ans[i]<<endl;
              i++;
              }
              
              return 0;
    }
            
              
