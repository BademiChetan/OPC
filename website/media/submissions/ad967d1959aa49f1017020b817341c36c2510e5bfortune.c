#include<stdio.h>

int main()
{
	int T,i,N;
	int a[1000][2];
	scanf("%d",&T);
		for(i=0;i<T;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(i=0;i<T;i++)
		{
			N=2;
			while(a[i][0]!=0)		
			{
				N=N*N%a[i][1];
				a[i][0]--;
			}
	printf("%d\n",N);
		}
return 0;	
}
