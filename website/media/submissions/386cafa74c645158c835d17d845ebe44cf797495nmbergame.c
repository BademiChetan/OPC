
#include<stdio.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
     {
      long int N,sum=0;
      long int ans,tot;
      scanf("%d",&N);
      long int i,temp;
      for(i=0;i<N;i++)
      {
       scanf("%d",&temp);
       sum+=temp;
      }
       N=N-1;
       tot=(N)*(N-1);
       tot=tot/2;
       ans=sum-tot;
       if(ans%2==0)
         printf("WIN\n");
       else
        printf("LOSE\n");
    }
   return 0;
}
