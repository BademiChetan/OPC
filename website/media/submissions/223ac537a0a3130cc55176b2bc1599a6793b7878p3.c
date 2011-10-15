#include<stdio.h>
int main()
{
int p,t,n,temp,sum;
  scanf("%d",&t);

	while(t--)
   {
     scanf("%d",&n);
	 sum=0;
    p=n;
	while(n--)
    {
      scanf("%d",&temp);
      sum=sum+temp;
    }
  sum=sum-(p*(p-1))/2; 
 if(sum%2==0)
   printf("\nLOSE");
  else
	printf("\nWIN");
  }
return 0;
}
