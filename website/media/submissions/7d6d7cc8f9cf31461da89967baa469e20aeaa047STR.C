#include<stdio.h>
int main()
{
	int t;
	
	long m,k,n=0,i,j,len1,t1,l1;
	char str[10000];
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld\n",&len1);
		for(i=0;i<len1;i++)
			scanf("%c",&str[i]);
		scanf("\n");
		scanf("%ld",&t1);
		while(t1--)
		{
			scanf("%ld",&m);
		scanf("%ld",&k);
		l1 = len1-k;
		for(i=0;i<=l1;i++)
	{
		for(j=m;j<k;j++)
		{
			if(str[i+j]!=str[j])
				break;
		}
		if(j==k)
			n++;
	}
	printf("%ld\n",n);
	n=0;
		}
	}
	return 0;
}