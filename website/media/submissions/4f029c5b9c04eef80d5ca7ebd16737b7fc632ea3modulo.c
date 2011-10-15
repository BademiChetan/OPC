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


      exp=(2<<(mod-1))*(2<<(mod-1));
      printf("%lld",exp);
   }

}
