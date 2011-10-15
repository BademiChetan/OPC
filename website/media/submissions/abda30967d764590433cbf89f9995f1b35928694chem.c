#include<stdio.h>
main()
	{
		int test,a,numc,bud,num,diff,diff1,total;
		long val,cost;
		scanf("%d",&test);
		while(test>0)
			{int s=0;
				scanf("%d%d",&numc,&bud);
				a=numc;
				while(numc>0)
					{
						scanf("%ld%ld%d",&cost,&val,&num);
						s=s+num;
						if(numc==a)
						diff1=val-cost;

						diff=val-cost;
						if(diff>diff1)
						{	diff1=diff;
							
						
						}
						numc--;



					}					
					total=s*diff1;
					printf("%d\n",total);
				test--;
			}
	}
