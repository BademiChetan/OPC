
#include<stdio.h>

int main()
{
    int test;
    scanf("%d",&test);
    if((1<=test)&&(test<=100))
    {
     while(test--)
      {
       long int N,sum=0;
       long int ans,tot;
       scanf("%d",&N);
       if((1<=N)&&(N<=100))
       {
        long int i,temp;
        for(i=0;i<N;i++)
        {
         scanf("%d",&temp);
         sum+=temp;
        }
         tot=(N)*(N-1);
         tot=tot/2;
         ans=sum-tot;
         if(ans%2==1)
           printf("WIN\n");
         else
          printf("LOSE\n");
       }
      }
    }
     return 0;
}
