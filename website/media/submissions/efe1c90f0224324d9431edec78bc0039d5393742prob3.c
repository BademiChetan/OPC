#include <stdio.h>

int main()
{	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N, k;
		scanf("%d %d", &N, &k);
		int s=2, i;
		for(i=0; i<N; i++)
		{
			s = s*s;
		}
		if(s<k)			
		printf("%d\n", s);
		else
		printf("%d\n", s%k);
	}
	return 0;
}
