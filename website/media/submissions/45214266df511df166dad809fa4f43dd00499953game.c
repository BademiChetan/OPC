#include <stdio.h>
int main ()
{
	int cases1,cases,sum,num;
	scanf("%d\n",&cases1);
	while (cases1--)
	{
		scanf("%d\n",&cases);
		sum = 0;
		while (cases--)
		{
			scanf("%d ",&num);
			sum += num;
		}
		if (sum%2)
			printf("LOSE\n");
		else printf("WIN\n");
	}
	return 0;
}
