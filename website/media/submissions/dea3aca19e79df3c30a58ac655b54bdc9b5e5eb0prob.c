#include<stdio.h>
int main()
{
	int a,b,c,n,i;
	scanf("%d",&n);
	while(n>0)
		{
			scanf("%d",&a);
			scanf("%d",&b);
			for(i=1;i<a;i++)
				{
					scanf("%d",&c);
					b=b+c-i;
				}
			if(b%2==0)
				printf("LOSE");
			else
				printf("WIN");
		}


return 0;
}
