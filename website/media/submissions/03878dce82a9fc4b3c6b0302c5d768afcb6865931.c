#include<stdio.h>
int main(void)
{
	int t,n,x,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x%2==1)
				ans++;
		}
		if(ans%2==0)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
	return 0;
}
