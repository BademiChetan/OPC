#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int jum = 0;
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			jum+=temp;
		}
		for(int i=1;i<n;i++)
		{
			jum-=i;
		//	printf("jum=%d\n",jum);
		}
	//	printf("%d mod 2=%d\n",jum,jum%2);
		if(jum%2==0)puts("LOSE");
		else puts("WIN");
	}
	return 0;
}
