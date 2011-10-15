
#include<stdio.h>
int main()
{
	int i,t,c,a,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		c=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a&1)
			c++;;
		}
		//c=c-n;
		 if(n&1)
		 {
			if(c&1)
			printf("LOSE\n");
			else
			printf("WIN\n");
		 }


		else
		 {
			if(c&1)
			printf("LOSE\n");
			else
			printf("WIN\n");
		 }
	}
   return 0;
}