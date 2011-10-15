#include<stdio.h>
int main()
{
int t,n,temp,sum;
  scanf("%d",&t);

	while(t--)
   {
     scanf("%d",&n);
	 sum=0;
	while(n--)
    {
      scanf("%d",&temp);
      sum=sum+temp;
    }
   if(sum%2==1)
   printf("\nLOSE");
  else
	printf("\nWIN");
  }
return 0;
}
