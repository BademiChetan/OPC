#include<stdio.h>
#define N 1000001
int main()
{
	int t;
	long x,y,r,max;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&x,&y);
		max=y>x?y:x;
		r=(N+y-x)%N;
		if(r<=max)
			printf("%ld\n",r);
		else
		{
			if(N-1-r==0)
				printf("N\n");
			else
				printf("N - %ld\n",N-1-r);
		}
	}
	return 0;
}