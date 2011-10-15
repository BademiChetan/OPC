#include<stdio.h>

void main()
{
	int test,numbers,a,b,z[101],i;
	scanf("%d",&test);
	
	for(i=0;i<test;i++)
	{
                        scanf("%d",&numbers);
			scanf("%d",&a);
			scanf("%d",&b);
			z[i]=a+b-1;
	}
	for(i=0;i<test;i++)
	{
			if(z[i]%2==0)
				printf("LOSE\n");
			else
				printf("WIN\n");
	}
		
}
