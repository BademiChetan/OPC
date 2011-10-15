#include<stdio.h>

int main()
{
  int t,n,s,i,r;
  scanf("%d",&t);
  while (t--)
    {
      scanf("%d",&n);
      for (i=0,s=0;i<n;i++)
	{
	  scanf("%d",&r);
	  s+=r;
	}
      s-=(n*(n-1))/2;
      if (s%2)
	printf("WIN\n");
      else
	printf("LOSE\n");
    }
  return 0;
}
