#include<stdio.h>

int main()
{
  int t;
  long long int n,k,a=2;
  scanf("%d",&t);
  while (t--)
    {
      scanf("%lld%lld",&n,&k);
      if (n>k)
	n=n%k;
      while (n--)
	a*=a;
      printf("%lld\n",a);
    }
  return 0;
}
