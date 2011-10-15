#include<stdio.h>
void main()
{
	int n,a,i,k=0,b,d;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		for(i=a;i>0;i--)
		{scanf("%d",&b);
			k=k+b;
			getchar();
		}
		d=k-a*(a-1)/2;

		if(d%2)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
}

