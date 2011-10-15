#include <stdio.h>
int main()
{
	int arr[100][100], i=0, j=0, t, a[100], b[100],z;
	scanf("%d", &t);
	i=t;
	while(i>0)
	{
		scanf("%d%d", &a[i-1], &b[i-1]);
		i--;
	}
	i=0;
	while(i<100)
	{
		j=i;
		z=0;
		while(j<100)
		{

			arr[i][j]=z;
			if(j==99)
			{
				j=-1;
			}
			if(j==(i-1))
			{
				break;
			}
			j++;
			z++;
		}
		i++;
	}
	t=t-1;
	while(t>=0)
	{
		printf("%d\n", arr[a[t]][b[t]]);
		t--;
	}
	return 0;
}