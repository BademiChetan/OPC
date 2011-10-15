#include<stdio.h>
#include<stdlib.h>
main()
{
	int ctr,t,count=0;
	double n,k,prod=2.0,*output;
	scanf("%d",&t);
	output = (double *)malloc(sizeof(double)*t);
	while(t!=0)
	{
		prod = 2.0;
		scanf("%lf %lf", &n, &k); 
		while(n!=0)
		{
			prod = prod * prod;
			while(prod > k)
				prod = prod-k;
			n--;
		}
		output[count] = prod;
		count++;
		t--;
	}
	for(ctr=0;ctr<count;ctr++)
		printf("%d\n",(int)output[ctr]);
}
		
