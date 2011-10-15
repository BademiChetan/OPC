
#include<stdio.h>
int main()
{
	int i,t,c,a,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		c=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);

			c=c+a;
		}
		c=c-n*(n+1)/2+n;

			if(c&1)
			printf("WIN\n");
			else
			printf("LOSE\n");

	}
   return 0;
}