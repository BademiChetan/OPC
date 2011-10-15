
#include<stdio.h>
int main()
{
		int t,x,y,q,k,l,r;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d %d",&x,&y);
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
			printf("%d\n",k);
		}
      return 0;
}