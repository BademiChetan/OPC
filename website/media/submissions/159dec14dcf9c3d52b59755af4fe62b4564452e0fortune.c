#include<stdio.h>

int main()
{
  int t;
  long long int n,k,a;
  scanf("%d",&t);
  while (t--)
    {
      a=2;
      scanf("%lld%lld",&n,&k);
      if (n>k)
	n=n%k;
      a=a<<((n*(n+1))/2);
      printf("%lld\n",a);
    }
  return 0;
}
