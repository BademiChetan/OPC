#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,k,sum,i,temp,sroot,half;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		sum =2;
		while(n--)
		{						
			sroot = floor(sqrt(k));	
			if(sum<sroot)
				sum = sum*sum;
			else
			{
				temp = sum;				
				for(i=0;i<temp;i++)
				{
					half = k/2;					
					if(sum<=half)
						sum = sum + sum;
					else
						sum = (sum + sum)-k;
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
