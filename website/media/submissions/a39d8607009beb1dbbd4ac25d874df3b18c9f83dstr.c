#include<stdio.h>
void main()
{
	int t,n,m=1,k;
	long pow=1,i;
	scanf("%d",&t);
	while(t-->0)
	{	m=pow=1;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)	
			pow*=2;
		for(i=1;i<=pow;i++)
		{
			m=(2*m)%k;
		}
		printf("\n%d",m);
	}	
}
