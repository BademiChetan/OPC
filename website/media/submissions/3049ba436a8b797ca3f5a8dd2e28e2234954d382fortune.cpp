#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int tot = 2;
		for(int i=1;i<=n;i++)
		{
			tot%=k;
			tot = (tot*tot)%k;
		}
		printf("%d\n",tot);
	}
	return 0;
}
