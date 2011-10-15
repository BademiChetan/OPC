
#include<stdio.h>

main()
{
      int t,n,q,m,k,i,j,l=0,z=0,ans=0;
      scanf("%d",&t);
      while(t)
      {
                   scanf("%d",&n);
                   char str[n];
                   scanf("%s",str);
                   scanf("%d",&q);
                   for(i=0;i<q;i++)
                   {
                                  ans=0;
                                  l=0;
                                   scanf("%d",&m);
                                   scanf("%d",&k);
                                   char ns[k];
                            for(j=m-1;j<m+k-1;j++)
                           {
                               ns[l] =str[j];
                               l++;
                           }
                           ns[l] ='\0';
                             for (j=0;j<=n-k;j++)
                             {
                                  
                                 char temp[k];
                                 z=0;
                                 for(l=j;l<j+k;l++)
                                 {
                                      temp[z] = str[l];
                                      z++;           
                                 }
                                 temp[z]='\0';
                                     
                                                          
                                 for(l=0;l<k;l++)
                                 {
                                                 if(temp[l] != ns[l])
                                                 {
                                                            break;
                                                 }
                                 }    
                                 if(l==k)
                                 {
                                 ans++;
                                 }
                             }
                              printf("%d\n",ans);
                   }
         t--;                   
      }
      
}
