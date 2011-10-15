#include<stdio.h>
int main()
{
	int n,k,i,j,arr[10],t;
	scanf("%d",&t);
	scanf("%d",&n);
	if(t >=1 && t<=100)
	{
		for(i=0;i<n;i++)
		{
			arr[i]=i+1;
			printf("%d",arr[i]);
		}
		scanf("%d",&k);
		for(i=0,j=i+1;i<n;i++,j++)
		{
			if(((arr[i]+arr[j])/k)==0)
			{
				printf("%d",arr[i]);
			}
		}
	}
	return 0;
}