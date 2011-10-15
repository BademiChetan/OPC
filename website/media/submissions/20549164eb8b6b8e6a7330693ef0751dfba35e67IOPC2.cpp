#include<stdio.h>
using namespace std;
int main()
{
      int T,M,N,i,a,sum=0;
      scanf("%d",&T);
      while(T--)
      {
          scanf("%d",&N);
          for(i=0;i<N;i++)
          {
              scanf("%d",&a);
              sum+=a;
          }
          M=N*(N-1)/2;
          sum-=M;
          if(M%2!=0)
          {
                  if(sum%2==0)puts("LOSE");
                  else puts("WIN");
          }
          else
          {
                  if(sum%2==0)puts("WIN");
                  else puts("LOSE");
          }
      }
      
      return 0;
}
