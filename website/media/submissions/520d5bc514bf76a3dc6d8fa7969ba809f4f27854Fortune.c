#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,T,N,K,money;

	printf("Enter values within constraints only\n");
again:
	scanf("\n%d",&T);

	if(!(T>=1 && T<=1000))
		
		{printf("\nvalue entered is not accepted as per the constraints...Enter agian...\n");
		goto again;}
		int value[T];

	for(i=0;i<T;i++)
	{
		money = 2;
		again1:		
		scanf("\n%d %d",&N,&K);

		if(!(N>=1 && K<=1000000000))
			{printf("\nvalue entered is not accepted as per the constraints...Enter agian...\n");
			goto again1;}
		
		for(j=0;j<N;j++)
		{
			money = money*money;
		}
		
		value[i] = money % K;
	}
	for(i=0;i<T;i++)
	printf("\n%d",value[i]);
}
