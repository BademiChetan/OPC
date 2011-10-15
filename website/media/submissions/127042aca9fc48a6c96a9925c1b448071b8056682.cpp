#include <stdio.h>

int main()
{
	int T;
	scanf(" %d", &T);
	while(T -- > 0)
	{
		int n, sum = 0, temp;
		scanf(" %d", &n);
		for(int i = 0; i < n; i ++)
		{
			scanf(" %d", &temp);
			sum += temp;
		}
		sum -= (n * (n - 1) ) / 2;
		if(sum % 2 == 0)
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}
