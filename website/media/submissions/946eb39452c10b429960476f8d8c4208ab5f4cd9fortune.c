#include<stdio.h>
#include<math.h>

int main()
{
int T,i;
long long N,K,sol;
scanf("%d",&T);
while(T--)
{
 sol=2%K;
 scanf("%lld %lld",&N,&K);
 for(i=0;i<N;i++)
 {
  sol=((sol%K)*(sol%K))%K;
 }
 printf("%lld\n",sol);
}
return 0;
}
