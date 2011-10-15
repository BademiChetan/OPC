#include<stdio.h>
 main()
{
	 int K;
	int a,b,c,N;
	scanf("%d",&a);
		while(a>0)
		{	b=2;
			scanf("%d%d",&N,&K);
//		if(K%2!=0&&N>=1&&K>=1)	
//		{
		while(N>0)
				{
					b=b*b;
					c=b%K;
					N--;
				}
		printf("%d\n",c);
		a--;
//		}
		}

}
