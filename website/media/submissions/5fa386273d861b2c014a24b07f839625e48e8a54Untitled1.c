#include<stdio.h>
int main()
{
    int t,i,j,sum,n,temp;
scanf("%d",&t);
for(i=0;i<t;i++)
{
                scanf("%d",&n);
                sum=0;
                for(j=0;j<n;j++)
                {
                                scanf("%d",&temp);
                                sum+=temp;
                }
if((sum-((n-1)*n)/2)%2==1)printf("WIN");
else printf("LOSE");
}
return 0;
}
