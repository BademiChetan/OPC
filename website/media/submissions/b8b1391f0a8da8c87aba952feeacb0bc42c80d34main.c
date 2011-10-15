/*
 * main.c
 *
 *  Created on: 25-Sep-2011
 *      Author: pritesh
 */

#include<stdio.h>

int main()
{
	int a[100],n,i,sum=0,val=0,cases,c=0;
	scanf("%d",&cases);
	while(c<cases)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			val+=i;
		}
		if((sum-val)%2==0)
			printf("LOSE\n");
		else
			printf("WIN\n");
		c++;
	}
	return 0;
}
