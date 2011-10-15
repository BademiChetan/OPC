#include <stdio.h>
#include <stdlib.h>
int max2(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int N,count;
	int ans[10];//size
	scanf("%d",&N);
	//printf("x");
	for(count=0;count<N;count++)
	{
		//code
		int n,W,i,j;
		scanf("%d %d",&n,&W);
		int c[10][3];
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&c[i][0],&c[i][1],&c[i][2]);
		}
		//int max[10];
		int v[150];
		int w[150];
		int cnt=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<c[i][2];j++)
			{
				v[(cnt++)+1]=c[i][1];
				w[cnt]=c[i][0];
			}
		}
		int **V;
		V=(int**)malloc(sizeof(int*)*(cnt+1));
		for(i=0;i<(cnt+1);i++)
			V[i]=(int*)malloc((W+1)*sizeof(int));
		int w2;
		for(w2=0;w2<=W;w2++)
			V[0][w2]=0;
		for(i=1;i<=cnt;i++)
			for(w2=0;w2<=W;w2++)
				if(w[i]<=w2)
					V[i][w2]=max2(V[i-1][w2],v[i]+V[i-1][w2-w[i]]);
				else
					V[i][w2]=V[i-1][w2];
		ans[count]=V[cnt][W];//enter ans
	}
	for(count=0;count<N;count++)
	{
		printf("%d\n",ans[count]);
	}
	return 0;
}
