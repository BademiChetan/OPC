#include<stdio.h>
int main()
{
	int t,n,k,i=2,j,r;
	scanf("%d",&t);
	if(t>0 && t<=1000)
	{
		for(i=0;i<t;i++)
		{
			scanf("%d %d",&n,&k);
		}
		for(j=1;j<=n;j++)
		{
			i=i*i;
			r=i%k;
			printf("%d\n",r);
		}
	}
	return 0;
}