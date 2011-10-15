#include<stdio.h>
int main()
{
	int x,y,N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d  %d",&x,&y);
		printf("%d\n",y-x);
	}
	return 0;
}


