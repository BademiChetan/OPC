#include<stdio.h>
int main()
{
	int t;
	long x,y,r;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&x,&y);
		r=y%(x+1);

			printf("%ld\n",r);
	}
	return 0;
}