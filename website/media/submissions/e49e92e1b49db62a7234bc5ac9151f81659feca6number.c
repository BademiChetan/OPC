#include <stdio.h>

int main()
{
	int cases,i,no[100],a[100][100],j;
	int flag;
	scanf("%d",&cases);
	for(i=0;i<cases;i++)
	{
	flag=0;
	scanf("%d",&no[i]);
	for(j=0;j<no[i];j++)
	{
	scanf("%d",&a[i][j]);
	flag=flag+a[i][j]-(j+1);
	}
	if(flag%2==0)
		printf("LOSE\n");
	else
		printf("WIN\n");
	}
	return 0;
}