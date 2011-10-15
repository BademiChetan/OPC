#include<stdio.h>
int main()
{
    int t,n,sum,i,j,m;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
                    sum=0;
                    scanf("%d",&n);
                    for(j=0;j<n;j++)
                    {
                                    scanf("%d",&m);
                                    sum+=m;
                                    }
                    if(n%2==0)
                    {
                              if(sum%2==0)
                              printf("WIN\n");
                              else
                              printf("LOSE\n");
                              }
                    else
                    {
                        if(sum%2==0)
                              printf("LOSE\n");
                              else
                              printf("WIN\n");
                              }
                              }
  // getch();
   return 0;
}
                        
