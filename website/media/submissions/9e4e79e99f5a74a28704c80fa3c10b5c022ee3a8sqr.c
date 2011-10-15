#include<stdio.h>
#define N 1000001
int main()
{
	int t;
	long x,y,r;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&x,&y);
		r=(N+y-x)%N;

			printf("%ld\n",r);
	}
	return 0;
}