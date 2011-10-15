#include<iostream>
using namespace std;
#include<string.h>


int main()
{
    
    int t,i,j,m,k,q,l,r,z;
    cin>>t;
    int n[t];
    
    if((t>=1)&&(t<=10))
    for(i=1;i<=t;i++)
    {
      cin>>n[i];
      if((n[i]>=1)&&(n[i]<=50000))
      {
    
                                 char s[n[i]];
    
                                 for(l=0;l<n[i];l++)
                                 cin>>s[l];
                                 
                                 cin>>q;
                                 
                                 if((q>=1)&&(q<=50000))             
                                 { 
                                   int cnt[q];
                                   for(r=1;r<=q;r++)
                                   {   cnt[r]=0;
                                        }
                                   
                                   for(r=1;r<=q;r++)
                                   {
                                    cin>>m>>k;
                                    if((m>=0)&&(m<n[i])&&(k>=1)&&((m+k-1)<n[i]))
                                     {
                                    
                                      l=m;
                                      char c[k-m+1];
     
                                      for(j=0;j<=(k-m);j++)
                                      {
                                         c[j]=s[l];
                                         l++ ;
                                          }
    
                                     char temp[k-m+1];
                                     
                                     for(j=0;j<n[i]-(k-m);j++)
                                     { 
                                      for(z=j,l=0;z<(k-m+1+j);z++,l++) 
                                       temp[l]=s[z];
                                       
                                         if(strcmp(temp,c)==0)
                                           (cnt[r])++;
                                          }
                                     cout<<cnt[r];    
                                         }
                                     }
                                     for(r=1;r<=q;r++)
                                     cout<<cnt[r]<<"\n";
                                
    
                   
  }
 }   
}
    
    return 0;



}                 
