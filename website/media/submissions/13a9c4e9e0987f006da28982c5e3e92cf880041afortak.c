# include <stdio.h>
# include <math.h>

int phi(int n)
{
	int ph = 1;
	int i, sq = sqrt(n);
	int j = 0;
	for( i = 2; i <=sq; i++)
	{
		if( n%i == 0)
		{	
			printf("\n%d",i);
			n/=i;
			while(n%i==0)
			{
				ph*=i;
				n/=i;	
			}
			ph*=(i-1);
		}
	}
	if (n>1) return (ph*(n-1));
	return ph;
}

int ipow(int base, int exp, int mod)
{
    long int result = 1;
    while (exp)
    {
        if (exp & 1)
		{  
            result *= base;
			result = result % mod;
		}
        exp >>= 1;
        base = (base * base ) % mod;
    }
    return result;
}

int main()
{
	int n,k,t,i,x,y;	
 	scanf("%d",&t);
	
        for(i=1;i<=t;i++)
        {
                scanf("%d %d",&n,&k);
                //x = pow(2,n);
                //y = pow(2,x) % k;
                if(n>(k+1))
                {
                        printf("1\n");
                }
                else
                {
                        x = ipow(2,n, phi(k));
                        y = ipow(2,x,k);
                        printf("%d\n",y);
                }
        }
return 0;
}

