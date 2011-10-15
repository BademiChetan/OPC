#include<stdio.h>
int main()
  {
    int t,n,sum,x,i;
    int arr[100];
    scanf("%d",&t);
    while(t--)
      {
        sum=0;
        x=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
          {
            scanf("%d",&arr[i]);
            sum+=arr[i];
          }
        for(i=1;i<n;i++)
          {
            x+=i;
          }
        sum=sum-x;
        if(sum%2==0)
          {
            printf("LOSE\n");
          }
        else
          {
            printf("WIN\n");
          }
      }
   return 0;
  }
