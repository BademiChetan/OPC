#include<iostream>

using namespace std;

int main()
{ int n=5;
int T;
    int a[n][n];
    int i,j,k;
      k=0;
    i=0;
    
    int x1,y1;
    
    for(j=0;j<n;j++)
        { 
          
          a[i][j]=k;
          k++;
          }
          
      j=0;
      k=1;    
      
  for(i=1;i<n;i++)
        { 
          
          a[i][j]=k;
          k++;
          }
    int b,c;      
          
     for(i=1;i<n;i++)
    { for(j=1;j<n;j++)
     { 
                     a[i][j]=0;
                     b=i;
                     c=j;
                     
                     do
                     {
                                
                        if((a[b][c]==a[--i][c]) || (a[b][c]==a[b][--j]))
                           a[b][c]=a[b][c]+1;
                           
                          } while(i>=0  &&  j>=0);
                           }   }                   
                           
          for(i=0;i<n;i++)
          {cout<<"\n";
          for(j=0;j<n;j++ )
                   cout<<a[i][j];
                   }
                   
         cout<<"\nEnter 'T'  no. of test cases::";
    cin>>T;
    int u;
    for(u=1;u<=T;u++)
    {
                     cout<<"Enter coordinates:";
                     cin>>x1>>y1;
                     
                     cout<<a[x1][y1];
                     }
                               
                   
                  
                   return 0;
                   }     
