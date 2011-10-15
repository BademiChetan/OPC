#include<stdio.h>
main()
{
	long int a,b,c,d=2,t,n,k;
	scanf("%ld",&t);
	for(a=0;a<t;a++)
	{
		d=2;
		scanf("%ld%ld",&n,&k);
		b=n%k;
		for(c=0;c<b;c++)
		{
			d=d*d;
		}
		printf("%ld\n",d);
	}
}
