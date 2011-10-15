#include<stdio.h>
int main()
{
	int t;
	long x,y,t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&x);
		scanf("%ld",&y);
		r=y-x;
		if(r<0)
			printf("%ld\n",1000000-1-r);
		else
			printf("%ld\n",r);
	}
	return 0;
}