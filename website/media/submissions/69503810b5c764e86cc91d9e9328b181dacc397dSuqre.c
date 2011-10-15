#include <stdio.h>
int main()
{
	int arr[6][6], i=0, j=0, t, a[6], b[6],z;
	scanf("%d", &t);
	i=t;
	while(i>0)
	{
		scanf("%d%d", &a[i-1], &b[i-1]);
		i--;
	}
	i=0;
	while(i<6)
	{
		j=i;
		z=0;
		while(j<6)
		{

			arr[i][j]=z;
			if(j==5)
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
