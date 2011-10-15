#include<stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i;
		int sum=0;
		int final;
		for(i=0;i<n;i++)
		{
			int num;
			scanf("%d",&num);
			sum+=num;
		}
		final=sum-n*(n-1)/2;
		if(final%2==0)
		{
			printf("LOSE\n");
		}
		else
		{
			printf("WIN\n");
		}
	}
}
