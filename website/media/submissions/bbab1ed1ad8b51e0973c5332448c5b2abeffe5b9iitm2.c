#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a,b;
	int i=0;
	int sum = 0;
	int inputnum = 0;
	char output[100][4];
	char output1[100][4];
//	for(i=0;i<100;i++)
//		strcpy(output[i],"\0");
	scanf("%d",&a);
	inputnum = a;
	while(a>0)
	{
		scanf("%d",&b);
		sum = 0;
		int *arr = (int *)(malloc(sizeof(int)*b));
		
		for(i=0;i<b;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(i=0;i<b;i++)
		{
			sum = sum +arr[i];
		}
		for(i=b-1;i>=0;i--)
		{
			sum = sum - i;
		}
		
	int x=sum%2;
//	printf("x is %d \n",x);
	if(x==0)
	{
		strcpy(output[a],"LOSE");
		strcpy(output1[a],"WIN");
		a--;
	}
	else
		strcpy(output[a--],"WIN");
	
		
		
		}
	//	printf("output[inputnum] is %s",output1[inputnum]);
	for(i=inputnum;i>0;i--)
	{
		if(strcmp(output1[i],"WIN")==0)
		printf("LOSE\n");
		else
		printf("%s\n",output[i]);
	}	
		
		
}
		
