#include <stdio.h>
int main()
{
	int arr[50][50], i=0, j=0, t, a[50], b[50],z;
	scanf("%d", &t);
	i=t;
	while(i>0)
	{
		scanf("%d%d", &a[i-1], &b[i-1]);
		i--;
	}
	i=0;
	while(i<50)
	{
		j=i;
		z=0;
		while(j<50)
		{

			arr[i][j]=z;
			if(j==49)
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

