#include <stdio.h>

int main()
{
	int N;
	int array[102];
	
	int i=0;
	int sum=0;
	int T;
	scanf("%d",&T);
	int k=0;
	
	for(k=0;k<T;k++)
	{
		scanf("%d",&N);
		int j=0;
		for(j=0;j<=N-1;j++)
		{
			scanf("%d",&array[j]);
		}
		
		
		int len=j-1;
		for(i=0;i<=len;i++)
		{
			sum=array[i]+sum;
		}	
		
		sum=sum-(N*(N-1)/2);
		if(sum%2==0){
		printf("lose\n");
		}
		else{
		printf("won\n");
		}
			sum=0;
	}
	
	
	
	//int y=5;
	
}
