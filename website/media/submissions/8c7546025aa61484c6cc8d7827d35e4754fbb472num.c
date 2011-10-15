#include<stdio.h>
int main()
{
	int t,n,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int s=0,l,j;
		scanf("%d",&l);
		for(j=0;j<l;j++)
		{
			scanf("%d",&n);
			s+=n;
		}
		if((s-l*(l-1)/2)%2)
		{
			printf("WIN\n");
		}
		else
 		{
			printf("LOSE\n");
		}
	}
	return 0;
}
