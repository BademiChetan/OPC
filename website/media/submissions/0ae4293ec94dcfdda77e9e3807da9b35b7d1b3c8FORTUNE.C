#include <stdio.h>

int main()
{
  long N[1000],K[1000],X,temp,res;
  int T,M;
  scanf("%d",&T);
  for(M=0;M<T;M++)
      scanf("%ld%ld",&N[M],&K[M]);

  for(M=0;M<T;M++)
    {
      temp=N[M]%K[M];
       res=2;
	for(X=0;X<temp;X++)
	 res=res*res;
      printf("\n%ld",res);
   }
return 0;
}