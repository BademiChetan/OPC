
#include<stdio.h>
void main()
{
    int times;
    scanf("%d",&times);
    int n[times];
    char ans[times][5];
    for(int k=0;k<times;k++)
    {
    scanf("%d",&n[k]);
    char arr[2*n[k]];
    scanf("%s",arr);
    int a[n[k]];
    int count=0;
    for(int i=0;i<2*n[k];i++)
    {
            if(arr[i]!=' ')
            {
                         a[count]=(int)(arr[i])-48;
                         count++;
            }
    }
    int t=1;
    while(count!=1)
    {
                   a[0]=a[0]+a[1]-t;
                   for(int i=1;i<count;i++)
                   {
                           a[i]=a[i+1];
                   }
                   count--;
    }
    if(a[0]%2==0)
    {
                 ans[k][0]='W';
                 ans[k][1]='I';
                 ans[k][2]='N';
    }
    else
    {
                 ans[k][0]='L';
                 ans[k][1]='O';
                 ans[k][2]='S';
                 ans[k][2]='E';
    }
    }
    for(int k=0;k<times;k++)
    {
    printf("%s",ans[times]);
    }
     }
