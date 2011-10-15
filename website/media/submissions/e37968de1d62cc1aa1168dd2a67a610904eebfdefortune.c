#include<stdio.h>
#include<math.h>
void main()
{
	int k, n;
	int amt;
	int cases;
	int cnt1;

	scanf("%d", &cases);
	
	for(cnt1=0; cnt1<cases; cnt1++)
	{
		scanf("%d",&n);
	
		scanf(" %d",&k);
	
		amt=pow(2,2*n);

		amt=amt%k;
	
		printf("%d\n",amt);
	}

	
}