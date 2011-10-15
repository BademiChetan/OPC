#include<stdio.h>
#include<string.h>

int main()
{
  int t;
  long n,q,m,k,l,i,j,c;
  char a[50000],te[50000];
  scanf("%d",&t);
  while(t--)
    {
      scanf("%ld",&n);
      //     for (i=0;i<n;i++)
      //	a[i]=getchar();
      scanf("%s",a);
      scanf("%ld",&q);
      while (q--)
	{
	  scanf("%ld%ld",&m,&k);
	  strncpy(te,a+m,k);
	  for (i=0,l=n-k,c=0;i<=l;i++)
	    if (strncmp(a+i,te,k)==0)
	      c++;
	  printf("%ld\n",c);
	}
    }
  return 0;
}
