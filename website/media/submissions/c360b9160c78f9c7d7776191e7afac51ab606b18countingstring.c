#include <stdio.h>
main()
{
int testcase;
scanf("%d",&testcase);
int i=0,j,k,l;
int lenstr,noOfQueries;
int p;
while(i<=(testcase-1))
	{
		scanf("%d",&lenstr);
		char string[lenstr];
		for(j=0;j<lenstr;j++)
		{
			scanf("%c",&string[j]);
		}
		scanf("%d",&noOfQueries);
		int count[noOfQueries];
		int range1[noOfQueries],range2[noOfQueries];
		for(j=0;j<noOfQueries;j++)
		{
			scanf("%d%d",&range1[j],&range2[j]);
		}
		for(j=0;j<noOfQueries;j++)
		{
			char c=string[range1[0]];
			for(k=0;k<=lenstr;k++)
			{	
				p=k;
				for(l=0;l<(range2[j]-range1[j]);l++)
				{
					if(string[range1[l]]==string[p])
					{
					p=p+1;
					}
					else
					break;
				}
				if(p==(range2[j]-range1[j]))
				{
					count[j]=count[j]+1;
				}
			}
		}
		for(i=0;i<noOfQueries;i++)
		{
			printf("%d\n",count[i]);
		}
		i++;
	}
}

					
