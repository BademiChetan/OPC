#include<stdio.h>
#include<math.h>

int main()
{
int T,i,N;
long long K,sol,x;
scanf("%d",&T);
while(T--)
{
 sol=2%K;
 scanf("%d %lld",&N,&K);
 for(i=0;i<N;i++)
 {
  x=sol%K;
  sol=(x*x)%K;
 }
 printf("%lld\n",sol);
}
return 0;
}
