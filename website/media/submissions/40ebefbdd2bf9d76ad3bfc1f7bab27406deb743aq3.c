#include<stdio.h>

main()
{
	int t, i;
	long int nofd,k,sum;

	scanf("%d", &t);

	while(t--)
	{
		sum=2;	
		scanf("%ld %ld", &nofd, &k);

		for(i=0;i<nofd;i++)
		{
			sum=sum*sum;
			sum=sum%k;
			
			if(sum==1||sum==0)
				break;
		}
		
		printf("%ld\n", sum);
	}
}
