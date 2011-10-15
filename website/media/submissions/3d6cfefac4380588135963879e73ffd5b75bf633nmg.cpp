
#include<stdio.h>
using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
      while(test--)
      {
       long int N,sum=0;
       long int ans,tot=0;
       scanf("%ld",&N);
       long int i,temp;
        for(i=0;i<N;i++)
        {
         scanf("%ld",&temp);
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
     return 0;
}
