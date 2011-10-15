#include<stdio.h>

int main()
{
  int i,n,k,j,a[30];
  scanf("%d",&n);
  i=1;
  k=0;
  while(i<=n)
  {
    if(n%i==0)
      k++;
    if(k==2)
    {
      for(j=0;j<n;j++)
      {
	a[j]=i;
      }
    }
    i++;
  }
    for(j=0;j<n;j++)
      printf("%d   ",a[j]);


  return 0;
}