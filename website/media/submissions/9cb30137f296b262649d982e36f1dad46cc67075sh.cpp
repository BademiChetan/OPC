#include<stdio.h>
int main()
{
    int n=15;
    int a[n][n],i,j,k;
    for(i=0;i<n;i++)
    {
                    for(j=0;j<n;j++)
                    {
                                    int no=0,flag=0;
                                    do
                                    {
                                    flag=0;
                                    if(i!=0)    
                                    for(int k=i-1;k>=0;k--)
                                    {
                                            if(a[k][j]==no)
                                            {
                                                           flag=1;
                                                           no++;
                                                           break;
                                            }
                                    }
                                    if(j!=0)
                                    for(int k=j-1;k>=0;k--)
                                    {
                                            if(a[i][k]==no)
                                            {
                                                           flag=1;
                                                           no++;
                                                           break;
                                            }
                                    }
                                    }while(flag==1);
                                    a[i][j]=no;
                    }
    }
    int t;
    scanf("%d",&t);
    int x[t],y[t];
    for(i=0;i<t;i++)
    {
     cin>>x[i];
     cin>>y[i];
     }
    for(i=0;i<t;i++)
    {
                     printf("%d\n",a[x[i]][y[i]]);
                    
    }
    getch();
}
