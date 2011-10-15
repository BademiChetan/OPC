
#include<stdio.h>
#include<conio.h>
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
                                   int st=m-1;
                             for (j=0;j<n;j++)
                             {
                                 if(st == m+k-1)
                                 {
                                       st = m-1;
                                 }
                                 if(str[j] == str[st])
                                 {
                                       ans++;
                                         st++;
                                 }       
                                 
                                 
                             }
                              printf("%d\n",ans/k);
                   }
         t--;                   
      }
      
}
