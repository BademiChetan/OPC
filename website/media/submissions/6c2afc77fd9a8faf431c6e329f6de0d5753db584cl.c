#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,a,b;
	long long int *g;
	scanf("%d",&n);
	g=malloc(sizeof(long long int)*n);
	for(i=0;i<n;i++)
	{
		 scanf("%d %d",&a,&b);
		 g[i]=b-a;
	}
	for(i=0;i<n;i++)
		printf("%lld\n",g[i]);
	return 0;
}
