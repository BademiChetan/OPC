#include <stdio.h>

main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		int j,n;
		scanf("%d",&n);
		int num;
		int sum=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&num);
			sum += num;
		}
		if((sum-n+1)%2==0)
			printf("LOSE");
		else
			printf("WIN");
	}
}
