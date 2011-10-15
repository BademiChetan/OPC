#include<stdio.h>
int main(void)
{
	int t,n,x,i,ans,e;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x%2==0)
				ans++;
		}
		e=n-ans;
		if((ans)%2==0)
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}
