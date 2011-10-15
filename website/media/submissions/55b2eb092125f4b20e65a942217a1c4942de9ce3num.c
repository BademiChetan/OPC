#include<stdio.h>

int main()
{
	int t,n,a[100],i,j,x;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		a[i]=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&x);
			a[i]+=x;
		}
		x=a[i]+((n*(n-1))/2);
		a[i]=x;
	}
	for(i=0;i<t;i++)
	{
		if(a[i]%2!=0)
		{
			printf("WIN\n");
		}
		else
		{
			printf("LOSE\n");		
		}
	}
	return 0;
}
