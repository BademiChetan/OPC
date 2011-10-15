#include <stdio.h>
int main ()
{
	int cases1,cases,sum,num,n1,j;
	scanf("%d\n",&cases1);
	while (cases1--)
	{
		scanf("%d\n",&cases);
		sum = 0;
		j =0;
		while (cases--)
		{
			j++;
			scanf("%d ",&num);
			sum += num;
			
		}
		sum -= ((j-1)*(j))/2;
		if (!(sum&1))
			printf("LOSE\n");
		else printf("WIN\n");
	}
	return 0;
}
