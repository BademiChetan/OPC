#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int t, n , i , num , sum ;
	int turn ;
	int val ; 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum = 0 ; 
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&num);
			sum += num ;
		}
		turn = ((n-1)*n)/2 ; 
		sum -= turn ;
		if(sum %2 == 0)
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}
