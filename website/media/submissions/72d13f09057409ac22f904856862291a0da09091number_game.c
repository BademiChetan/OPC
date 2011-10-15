#include<stdio.h>
#define NATURAL_SUM(n) ((n*(n+1))/2)
int main()
{
	int t,i,n,sum=0,num,turn;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&num);
			sum=sum+num;
		}
		turn=n-1;
		sum=sum-NATURAL_SUM(turn);
		if(sum%2==0)
			puts("LOSE");
		else
			puts("WIN");
	}
	return 0;
}
		
