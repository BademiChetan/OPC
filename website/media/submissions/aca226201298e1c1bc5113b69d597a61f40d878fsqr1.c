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
		r=(max+y-x)%max;
		printf("%ld\n",r);
	}
	return 0;
}