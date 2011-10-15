#include<stdio.h>
using namespace std;
int main()
{
      int T,M,N,i,a,sum;
      scanf("%d",&T);
      while(T--)
      {
          sum=0;
          scanf("%d",&N);
          for(i=0;i<N;i++)
          {
              scanf("%d",&a);
              sum+=a;
          }
          M=N*(N-1)/2;
          sum-=M;
          if(sum%2==0)
          printf("LOSE");
          else
          printf("WIN");
      }
      
      return 0;
}
