#include<stdio.h>
#include<conio.h>
int main()
{
	int t , n ,i=1, j=1,x,turn=0;
	int arr[100];
	scanf("%d", &t);
	
	for(i=1;i<=t;i++)
	{
		turn++;
		x=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&arr[x++]);	
		}
		int temp;
		for(j=0;j<n-1;j++)
		{
			temp = arr[j] + arr[j+1] - turn;
			arr[j+1] = temp;
		}
		 if(arr[j-1]%2==0)
			printf("LOSE\n");
		else
			printf("WIN\n");
	
	
	}
	return 0;




}