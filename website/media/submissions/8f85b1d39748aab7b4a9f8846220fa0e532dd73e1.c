#include<stdio.h>
int main()
{
	int x,y,N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d  %d",&x,&y);
		if(y>x)
		printf("%d\n",y-x);
		else if(x>y)
			printf("%d\n",x+2-y);
		else
			printf("%d\n",0);
	}
	return 0;
}


