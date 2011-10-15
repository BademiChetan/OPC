# include <stdio.h>
# define MAX_WT 100000001
# define MAX_NO 15
# define MAX_IT 11

int m[MAX_IT][MAX_WT];
	int value[MAX_IT];
	int cost[MAX_IT];
	int nos[MAX_IT];

int main()
{
	int i,j,k,temp;
	int t,tc;
	int n,w;


	scanf("%d",&t);
	for(tc = 0; tc < t; tc++)
	{
		scanf("%d %d",&n,&w);
		for(j = 1; j <= n; j++)
			scanf("%d %d %d",&cost[j],&value[j],&nos[j]);

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= w; j++)
			{
				temp = 0;
				for( k = 0; k <= nos[i]; k++) 
				{
					if( (j-k*cost[i]) >= 0 ) 
						if((m[i-1][j-k*cost[i]] + k*value[i]) > temp ) temp = (m[i-1][j-k*cost[i]] + k*value[i]);
				}
				m[i][j] = temp;
			}
		}
	printf("%d\n",m[n][w]);	
	}
return 0;
}
