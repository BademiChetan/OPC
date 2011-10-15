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
		
	
	if(sum%2==0)
		strcpy(output[a],"LOSE");
	else
		strcpy(output[a],"WIN");
		
		a--;
		
		}
	for(i=inputnum;i>0;i--)
		printf("%s\n",output[i]);
		
		
		
}
		
