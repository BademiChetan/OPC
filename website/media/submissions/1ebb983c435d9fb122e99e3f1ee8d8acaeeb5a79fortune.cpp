#include<iostream>
#include<math.h>
using namespace std;

double mon(int);

int main()
{
    int t,i,j;
    cin>>t;
    
    int n[t],k[t],money[t],ans[t];
        
    if((t>=1)&&(t<=1000))
    for(i=1;i<=t;i++)
    {       
            cin>>n[i]>>k[i];
    
            if((n[i]>=1)&&(k[i]<=pow(10,9))&&((k[i]%2)!=0)) 
            {  
              
               money[i]=mon(n[i]);
               ans[i]=(money[i]%k[i]);
                              
                              }
         }
         
        for(i=1;i<=t;i++)
        {                if((n[i]!=0)&&(k[i]<=pow(10,9))) 
                         cout<<ans[i]<<"\n";
}
        return 0;
         
         }
    
                                                                                         
double mon(int n)
{
       if(n==0)
       return 2;
       else
       return pow(mon(n-1),2);
       
       }    