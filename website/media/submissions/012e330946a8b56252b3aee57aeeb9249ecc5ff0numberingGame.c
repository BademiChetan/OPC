#include<stdio.h>
int main()
{
	int n,a,i,j,b[102],t,sum=0,turn=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		sum=0;turn=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a);
			sum=sum+a;	
			turn=turn+j;
		}
		sum=sum-turn;
		if(sum%2==0)
		{
			b[i]=0;
		}
		else
		{
			b[i]=1;
		}
	}
	for(i=0;i<t;i++)
	{
		if(b[i]==0)
		{
			printf("LOSE\n");
		}
		else
		{
			printf("WIN\n");
		}
	}
	return 0;
}
		
