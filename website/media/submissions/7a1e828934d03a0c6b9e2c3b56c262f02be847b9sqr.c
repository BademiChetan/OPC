#include<stdio.h>
int main()
{
	int t;
	long x,y,r;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&x,&y);
		r=y-x;
		if(r<0)
			printf("%ld\n",1000001L-r);
		else
			printf("%ld\n",r);
	}
	return 0;
}