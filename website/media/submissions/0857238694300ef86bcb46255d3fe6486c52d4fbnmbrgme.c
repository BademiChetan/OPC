#include<stdio.h>

int main()
{
    int n,i,j,k,sum,ans[100],l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   sum=0;
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            scanf("%d",&l);
           sum+=l;
        }
        sum-=(n*(n-1))/2;
        ans[i]=sum%2;
    }
    for(i=0;i<n;i++)
    {
        if(ans[i]==0)
        printf("LOSE\n");
        else
        printf("WIN\n");
    }
   return 0;
}
