#include <stdio.h>
int main ()
{
	int cases1,cases,sum,num,n1;
	scanf("%d\n",&cases1);
	while (cases1--)
	{
		scanf("%d\n",&cases);
		sum = 0;
		cases--;
		scanf("%d ",&n1);
		while (cases--)
		{
			scanf("%d ",&num);
			if (!(n1&1 ^ num&1))
				n1 = 0;
			else n1 = 1;
			
		}
		if (n1&1)
			printf("LOSE\n");
		else printf("WIN\n");
	}
	return 0;
}
