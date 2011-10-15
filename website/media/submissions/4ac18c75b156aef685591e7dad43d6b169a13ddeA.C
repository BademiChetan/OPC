#include<stdio.h>
void main()
{
	int tc,n,a,i,j,res=0;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		res=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a);
			res+=a;
		}
		n--;
		res=res-((n*(n+1))/2);
		if((res%2)==1)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
}
