#include<stdio.h>
#include<stdlib.h>

int main()
{
	
	
	int i,j,T,N,K,m;

	printf("Enter values within constraints only\n");

	scanf("\n%d",&T);

	
		int value[T];

	for(i=0;i<T;i++)
	{
		m = 2;
		
		scanf("\n%d %d",&N,&K);

		
		
		for(j=0;j<N;j++)
		{
			m = m*m;
		}
		
		value[i] = m % K;
	}
	for(i=0;i<T;i++)
	printf("\n%d",value[i]);


}
