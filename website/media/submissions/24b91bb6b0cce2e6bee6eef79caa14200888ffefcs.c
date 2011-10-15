#include<stdio.h>
main()
{
      int t,n,q,m[50000][2],i,j,flag=0,r[50000]={0},k;
      char a[50000];
      scanf("%d",&t);
      scanf("%d",&n);
      scanf("%s",&a);
      scanf("%d",&q);           
      for(i=0;i<q;i++)
      {
                      scanf("%d %d",&m[i][0],&m[i][1]);
                      }
      for(i=0;i<q;i++)
      {
                      for(j=0;j<n;j++)
                      {
                                      if(a[j]==a[m[i][0]])
                                      {
                                                         for(k=1;k<m[i][1];k++)
                                                         {
                                                                                if(a[j+k]==a[(m[i][0])+k])
                                                                                {
                                                                                                          flag=1;
                                                                                                          }
                                                                                else
                                                                                {
                                                                                    flag=0;
                                                                                    break;
                                                                                    }
                                                                                    }
                                                         if(flag==1)
                                                         {
                                                                    r[i]++;
                                                                    }
                                                                    }
                                                                    }
                                                                    }
      for(i=0;i<q;i++)
      {
                      printf("%d",r[i]);
                      if(i!=q-1)
                      {
                                 printf("\n");
                                 }
                      }
      return 0;
      }
