#include<stdio.h>
#include<math.h>

int main()
{
	long int k,s,x,j;
	int t,i;
	long int a[1000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		x=2;
		scanf("%ld",&s);
		scanf("%ld",&k);
		for(j=1;j<=s;j++)
		{
			a[i]=x*x;
			x=a[i];
		}
		a[i]=x%k;
	
	}
	for(i=0;i<t;i++)
	{
		printf("%ld\n",a[i]);
	}		
	return 0;
}
