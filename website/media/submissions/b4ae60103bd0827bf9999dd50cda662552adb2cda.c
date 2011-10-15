#include<stdio.h>
int main()
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
			res=res^(a%2);
		}
		if(res==1)
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}
