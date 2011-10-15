#include <stdio.h>
void main()
{
	int n, k, j, sum=0,sum2=0;
	int T, p=0;
	printf("Enter no. of test cases : ");
	scanf("%d", &T);
	for (int v = 1; v<=T; v++)
	{
	printf("Enter the value of n\n");
	scanf("%d", &n);
	int array[1000];
	for( int i=0; i<n ; i++)
	{
		array[i] = i+1;
	}
	printf("Enter the value of k\n");
	scanf("%d", &k);
	for(i=0; i<n; i++)
	{
		for(j=i; j<n; j++)
		{
			sum= sum+array[j];
			if( sum%k ==0)
			p++;
			sum=sum2;
		}
		sum2= sum2+array[i];
		sum = sum2;
	}
	printf("The required no. of subsets is %d\n",p);
	}
}