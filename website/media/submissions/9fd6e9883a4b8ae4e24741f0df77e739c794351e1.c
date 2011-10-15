#include<stdio.h>
 main()
{
	 int K;
	int a,b,c,N;
	scanf("%d",&a);
		while(a>0)
		{	b=2;
			scanf("%d%d",&N,&K);
		if(K%2!=0)	
		{
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

}
