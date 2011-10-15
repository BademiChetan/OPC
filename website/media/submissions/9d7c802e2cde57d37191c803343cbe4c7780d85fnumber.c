#include<stdio.h>
int main()
{
	int t, n, i,j,f,a;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		f=0;
		scanf("%d", &n);
		for(j=0;j<n;j++)
		{
			scanf("%d", &a);
			f+=a;
		}
		if((n+f)%2)
			printf("LOSE\n");
		else	printf("WIN\n");

	}
	return 0;
}
