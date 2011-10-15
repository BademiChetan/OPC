#include<stdio.h>

int main()
{
	int i,j,k,t,n,bud,num,cost;
	long int value;
	int ourcost=0,on=0;
	scanf("%d\n",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&bud);
		
		for(j=0;j<n;j++)
		{
			scanf("%d%ld%d",&cost,&value,&num);
			for(k=0;k<num;k++)
			{
				ourcost+=cost;
				if(ourcost<=bud)
				{
					on+=value;
				}
				else
				{
					ourcost-=cost;
					break;
				}
			}
		}
		printf("%d\n",on);
	}
		
		return 0;
	}
