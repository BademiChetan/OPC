#include<iostream>

using namespace std;


int main()
{
    int t,k=1,x,y,n;
    int test;
              int p=5;

              int c=0;
    cin>>t;
    if(t>=1&&(t<=10000))
    {
int ax[(2*t)];
    int ans[t];
   
    for(int i=0;i<(2*t);i++)
    {
        cin>>ax[i];    
    }
    for(int z=0;z<(2*t);z=z+2)
    {
            if((ax[z]>=0)&&(ax[z+1]>=0)&&(ax[z]<=1000000)&&(ax[z+1]<=1000000))
            {
                if(ax[z]>=ax[z+1])
                n=ax[z]+1;
                else
                n=(ax[z+1]+1);
   
                          int a[n][n];

                                for(int i=0;i<n;i++)   
                                {
                                        for(int j=0;j<n;j++)
                                        {
                                                if(i==j)
                                                a[i][j]=0;
                                        }
                                }
                                   for(int i=0;i<(n-1);i++)      
                                       { 
                                           k=1;
                                            for(int j=(i+1);j<n;j++)
                                             {
                                                    a[i][j]=k++;
                                              }
                                      }
                            
                                      for(int i=(n-1);i>0;i--)   
                                      {
                                              p=n-1;
                                             for(int j=(i-1);j>=0;j--)
                                              {
                                                      a[i][j]=p--;
                                              }
                                         
                                      }
          
            
                                           cout<<endl<<a[ax[z]][ax[z+1]];
                        }
          }                   

 
    
    
    }  

            


            }
         
                    
                        
    
    
    
    

