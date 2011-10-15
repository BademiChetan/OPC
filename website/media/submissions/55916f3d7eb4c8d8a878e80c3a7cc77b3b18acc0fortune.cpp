#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int t,i,j;
    cin>>t;
    int n[t],k[t],money[t],ans[t];
    for(int i=1;i<=t;i++)
    money[i]=2;

    if((t>=1)&&(t<=1000))
    for(i=1;i<=t;i++)
    {       
            cin>>n[i]>>k[i];
            if((n[i]>=1)&&(k[i]<=pow(10,9))&&((k[i]%2)!=0)) 
            {  
               for(j=1;j<=n[i];j++)
                money[i]=pow(money[i],2);
                
                ans[i]=(money[i]%k[i]);
                              
                              }
         }
         
         for(i=1;i<=t;i++)
         cout<<ans[i]<<"\n";

         return 0;
         
         }
    
                                                                                         
