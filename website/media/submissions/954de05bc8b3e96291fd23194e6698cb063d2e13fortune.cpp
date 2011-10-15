#include<iostream>
#include<math.h>

using namespace std;

int mon(int);

int main()
{
    int t,i,j;
    cin>>t;
    
    int n[t],k[t],money[t],ans[t];
        
    if((t>=1)&&(t<=1000))
    for(i=1;i<=t;i++)
    {       
            cin>>n[i]>>k[i];
    
            if((n[i]>=1)&&(n[i]<=pow(10,9))&&(k[i]>=1)&&(k[i]<=pow(10,9))&&((k[i]%2)!=0)) 
            {  
              
               money[i]=mon(n[i]);
               ans[i]=(money[i]%k[i]);
                              
                              }
         }
         
        for(i=1;i<=t;i++)
        {                if((n[i]>=1)&&(n[i]<=pow(10,9))&&(k[i]>=1)&&(k[i]<=pow(10,9))&&((k[i]%2)!=0)) 
                         cout<<ans[i]<<"\n";
          }       
        
        return 0;
         
         }
    
                                                                                         
int mon(int n)
{
       if(n==0)
       return 2;
       else
       return (int)pow(mon(n-1),2);
       
       }    
