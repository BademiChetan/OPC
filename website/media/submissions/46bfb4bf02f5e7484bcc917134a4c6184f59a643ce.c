#include<stdio.h>

int main()
{
	int i,j,k,t,n,bud,num[15],cost[15];
	long int value[15];
	int ourcost=0,on=0;
	int temp,z;
	scanf("%d\n",&t);
	for(z=0;z<t;z++)
	{
		scanf("%d%d",&n,&bud);
		ourcost=0;
		for(j=0;j<n;j++)
		{
			scanf("%d%ld%d",&cost[j],&value[j],&num[j]);
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(value[i]<value[j])
				{
					temp=value[i];
					value[i]=value[j];
					value[j]=temp;
					temp=cost[i];
					cost[i]=cost[j];
					cost[j]=temp;
					temp=num[i];
					num[i]=num[j];
					num[j]=temp;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(k=0;k<num[i];k++)
			{
				ourcost+=cost[i];
				if(ourcost<=bud)
				{
					on+=value[i];
				}
				else
				{
					ourcost-=cost[i];
					break;
				}
			}
		}
		printf("%d\n",on);
	}
		
		return 0;
	}

