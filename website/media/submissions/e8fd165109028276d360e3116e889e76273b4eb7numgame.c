#include<stdio.h>
int main()
{
	int i,j,n,t,num,sum=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		sum=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&num);
			sum+=num;
			sum-=j;
		}
		j--;
		sum+=j;
		if(sum%2==0)
		printf("LOSE\n");
		else
		printf("WIN\n");
	}
	return 0;
}

