#include<stdio.h>
 main()
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
				printf("LOSE\n");
			else
				printf("WIN\n");
			n--;
		}



}
