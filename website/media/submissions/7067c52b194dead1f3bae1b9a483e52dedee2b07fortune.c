#include<stdio.h>
#include<stdlib.h>


void main()
{
	int T,flag=0;
	unsigned int N,K,j,unit=2;
	scanf("%d",&T);
	unsigned int arr[T];
	int i;
	for(i=0;i<T;i++)
	{
		scanf("%u %u", &N,&K);
		if((K&1)==0){printf("K should be odd");exit(0);}
		for(j=0;j<N;j++)
			{
			unit=unit*unit;
			if(unit>K) unit=(unit)%K;
			if(unit==0) {arr[i]=0;break;flag=1;}
			}
		if (flag==0)
			arr[i]=unit;
		flag=0;unit=2;
			
	}
		printf("Result is: \n");
	for(i=0;i<T;i++)
	{ printf("For Test Case %d \t",i+1);
		printf("Answer is %u \n",arr[i]);
	printf("-------------------------------\n");	
	}


}
