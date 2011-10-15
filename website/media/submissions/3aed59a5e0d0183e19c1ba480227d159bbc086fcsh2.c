
#include<stdio.h>
int main()
{
    int times;
    scanf("%d",&times);
    int n[times],k,i,j,m;
    char ans[times][4];
    char anss[8] = "winlose";
    for(k=0;k<times;k++)
    {
    scanf("%d",&n[k]);
    int a[n[k]];
    int count=0;
    for(m=0;m<n[k];m++)
    {
     scanf("%d",&a[m]);
     count++;
     }
    int t=1;
    while(count!=1)
    {
                   a[0]=a[0]+a[1]-t;
                   for(i=1;i<count;i++)
                   {
                           a[i]=a[i+1];
                   }
                   count--;
    }
    if(a[0]%2==0)
    {
                 for(m=0;m<3;m++)
                 ans[k][m]=anss[m];
    }
    else
    {
                 for(m=0;m<=4;m++)
                 ans[k][m]=anss[m+3];
    }
    }
    for(k=0;k<times;k++)
    {
    printf("%s\n",ans[k]);
    
    }
     }
