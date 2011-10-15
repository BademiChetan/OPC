#include <stdio.h>

void doit(void)
{
	int nos,count1=0,count0=0,flag=1,total,j,a;

	scanf("%d",&nos);
	
	total=nos;

	for(j=0;j<nos;j++)
	{
		scanf("%d",&a);

		if(a%2==0)
			count0++;

		else
			count1++;
	}

	while(nos%2==0)
	{
		if(total==1)
		{
			if(count1%2==0)
			{
				printf("LOSE\n");
				return;
			}

			else
			{
				printf("WIN\n");
				return;
			}
		}
		
		if(flag==1)
		{
			total--;
			count1++;
			flag=0;
		}

		else
		{
			if(count1%2==1)
			{

				if((total%2)%2==0)
					count1++;
			}

			else if(count0==0)
				count1++;

			total--;

			flag=1;
		}

	}

	if(nos%2!=0)
	{
		printf("LOSE\n");
		return;
	}
}

int main()
{
	int cases,i;

	scanf("%d",&cases);

	for(i=0;i<cases;i++)
	{
		doit();
	}
}
