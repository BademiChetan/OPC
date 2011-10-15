#include<stdio.h>
#include<stdlib.h>
main()
{
	int ctr,t,count=0,cnt=0;
	unsigned int prod = 2,k,*output;
	double n,temp;
	scanf("%d",&t);
	output = (unsigned int *)malloc(sizeof(unsigned int)*t);
	while(t!=0)
	{
		prod = 2;
		scanf("%lf %u", &n, &k); 
		while(n!=0)
		{
			if(prod!=65536)
				prod = prod * prod;
			else
			{
				for(cnt = 0;cnt<8;cnt++)
				{	prod = prod * 4;
					prod = prod % k;
				}
			}
			//printf("kk : %u\n",prod); 
			prod = prod % k;
			n--;
		}
		output[count] = prod;
		count++;
		t--;
	}
	for(ctr=0;ctr<count;ctr++)
		printf("%u\n",output[ctr]);
}
		
