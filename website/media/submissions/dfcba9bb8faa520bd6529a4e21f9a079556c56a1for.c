#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	int j;
	for(j=0;j<t;j++)
	{
		int ans=2;
		int n,k;
		scanf("%d %d",&n,&k);
		for(;n!=0;n--)
		{
			ans = (ans*ans)%k;
		}
		printf("%d\n",ans);
	}
}
