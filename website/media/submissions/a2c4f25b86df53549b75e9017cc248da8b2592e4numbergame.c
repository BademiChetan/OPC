#include<stdio.h>
#include<stdlib.h>

int main()
{
	int tnum=0, testcases, N, sum, tot, a, *answers, i;

	scanf("%d", &testcases);
	answers = (int *) malloc(testcases * sizeof(int));

	while(testcases--)
	{
		sum=0;
		scanf("%d", &N);
		tot = N*(N-1)/2;
		while(N--)
		{
			scanf("%d", &a);
			sum+=a;
		}	
		if((sum-tot)%2) answers[tnum++] = 1;
		else answers[tnum++] = 0;
	}
	for(i=0;i<tnum;i++)
		if(answers[i]==1)printf("WIN\n");
		else printf("LOSE\n");
	free(answers);
	return 0;
}
