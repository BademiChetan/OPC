#include <stdio.h>

int main()
{	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N, k;
		scanf("%d %d", &N, &k);
		int i, s=2;
		for(i=0; i<N; i++)
		{
			s = s*s;
		}
		printf("%d\n", s%k);
	}
	return 0;
}
