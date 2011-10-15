#include<stdio.h>
main()
{
	int t,a[100],x[100][2],i,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d",&x[i][0],&x[i][1]);
		a[i]=2;
		for(j=1;j<=x[i][0];j++)
		a[i]*=a[i];
		a[i]=a[i]%x[i][1];
	}
	for(i=1;i<=t;i++)
	printf("\n%d",a[i]);
}
		
