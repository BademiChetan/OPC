#include<stdio.h>
int main()
{
   long long n,j,k,exp,mod;
   int i,t;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
      scanf("%ll %ll",&n,&k);
      mod=n%k;


      exp=(2<<(mod-1))*(2<<(mod-1));
      printf("%ll",exp);
   }

}
