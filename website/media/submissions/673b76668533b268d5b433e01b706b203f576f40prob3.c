#include <stdio.h>
#include <math.h>

int main()
{	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N, k;
		scanf("%d %d", &N, &k);
		int s;
		s = pow(2, N);
		s = pow(2,s);		
		printf("%d\n", s%k);
	}
	return 0;
}
