#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t,i,j,k,max,value;
	int inp[10000][2];
	int **out;
	
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&inp[i][0]);
		scanf("%d",&inp[i][1]);
	}

	max = inp[0][0];

	for(i=0;i<t;i++)
	{
		if(max<inp[i][0])
			max = inp[i][0];
		if(max<inp[i][1])
			max = inp[i][1];
	}
	out = (int**)malloc((max+1)*sizeof(int*));
	for(i=0;i<=max;i++)
		out[i]=(int*)malloc((max+1)*sizeof(int));


	for(i=0;i<=max;i++)
	{
		for(j=0;j<=max;j++)
		{
			out[i][j]=0;
			for(k=0;k<j;k++)
			{
				if(out[i][j]==out[i][k])
					out[i][j]++;
			}
			for(k=0;k<i;k++)
			{
				if(out[i][j]==out[k][j])
					out[i][j]++;
			}
			
		}
	}
	for(i=0;i<t;i++)
	{
		j=inp[i][0];
		k=inp[i][1];
		printf("%d\n",out[j][k]);
 	}
	
	return 0;
}

