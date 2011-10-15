#include<stdio.h>
int main()
{
	long int K;
	int a,b,c,i,N;
	scanf("%d",&a);
		while(a>0)
		{	b=2;
			scanf("%d",&N);
			scanf("%ld",&K);
			for(i=1;i<=N;i++)
				{
					b=b*b;
					c=b%K;
				}
			printf("%d\n",c);
			a--;
		}

return 0;
}
