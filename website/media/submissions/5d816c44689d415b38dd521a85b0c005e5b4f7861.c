#include<stdio.h>
 main()
{
	 int K;
	int a,b,c,N;
	scanf("%d",&a);
		while(a>0)
		{	b=2;
			scanf("%d",&N);
			scanf("%d",&K);
			while(N>0)
				{
					b=b*b;
					c=b%K;
					N--;
				}
			printf("%d\n",c);
		a--;
		}

}