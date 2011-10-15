#include <stdio.h>

int main()
{
	int T;
	scanf(" %d", &T);
	while(T -- > 0)
	{
		int x, y;
		scanf(" %d %d", &x, &y);
		printf("%d\n", x ^ y);
	}
	return 0;
}
