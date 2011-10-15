
#include<stdio.h>
int main()
{
		long t,x,y,q,k,l,r;
		scanf("%ld",&t);
		while(t--)
		{
			scanf("%ld %ld",&x,&y);
			if(x==0||y==0)
			{
				k=x+y;
			}
			else if(x&1)
			{
				x++;
				q=y/(2*x);
				k=q*2*x;
				l=y%(2*x);
				r=l%x;
				if(l>=x)
				{
					k=k+2*x-r-1;
				}
				else
				{
					k=k+x-r-1;
				}
			}
			else
			{
				//x++;
				q=y/(2*x);
				k=q*2*x;
				l=y%(2*x);
				r=l%x;
				if(l>=x)
				{
					k=k+r;
				}
				else
				{
					k=k+x+r;
				}
			}
			printf("%ld\n",k);
		}
      return 0;
}