#include<stdio.h>

int main()
{
	int test,N,A,sumA,Ai,temp;

	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&N);
		sumA=0;
		temp=N;
		while(temp--)
		{
			scanf("%d",&Ai);
			sumA+=Ai;
		}
		sumA = sumA - ((N*(N-1))/2);

		if(sumA%2==0)
			printf("LOSE\n");
		else
			printf("WIN\n");

	}
	return 0;
}
