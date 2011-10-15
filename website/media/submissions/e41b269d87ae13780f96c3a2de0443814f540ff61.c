#include<stdio.h>

long long int sq(long long int n)
{
        long long int l = 0,m,h;
        for (h = 1;h*h <= n;h*=2)
        {while(l < h-1)
            {
                m = (l+h)>>1;
                if((m*m) <= n) l = m;
                else h = m;
            }
        }
        return l;
}
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
			sroot = sq(k);	
			if(sum<=sroot)
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
