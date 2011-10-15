#include<stdio.h>
int main()
{
   long long int n,j,k,exp,mod;
   int i,t;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
      scanf("%lld %lld",&n,&k);
      mod=n%k;
      j=1;
      exp=2;
      while(j<=mod)
      {
         exp=exp*exp;
         j++;
      }
      printf("%lld",exp);
   }

}
