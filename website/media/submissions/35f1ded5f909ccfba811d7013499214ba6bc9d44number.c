#include <stdio.h>

void doit(char ans[][5],int i)
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
	
	if(nos==1)
	{
		if(count1==1)
		{
			ans[i][0]='W';
			ans[i][1]='I';
			ans[i][2]='N';
			ans[i][3]=0;
			return;
		}
		
		else
		{
			ans[i][0]='L';
			ans[i][1]='O';
			ans[i][2]='S';
			ans[i][3]='E';
			ans[i][4]=0;
			return;
		}
	}

	while(nos%2==0)
	{
		if(total==1)
		{
			if(count1%2==0)
			{
				ans[i][0]='L';
				ans[i][1]='O';
				ans[i][2]='S';
				ans[i][3]='E';
				ans[i][4]=0;
				return;
			}

			else
			{
				ans[i][0]='W';
				ans[i][1]='I';
				ans[i][2]='N';
				ans[i][3]=0;
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
		ans[i][0]='L';
		ans[i][1]='O';
		ans[i][2]='S';
		ans[i][3]='E';
		ans[i][4]=0;
		return;
	}
}

int main()
{
	int cases,i;
	char ans[100][5];

	scanf("%d",&cases);

	for(i=0;i<cases;i++)
	{
		doit(ans,i);
	}

	for(i=0;i<cases;i++)
		printf("%s\n",ans[i]);
		
	return 0;
}
