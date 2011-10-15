#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int ntc,n,x;
	scanf("%d",&ntc);
	while(ntc--)
	{
		int sum = 0;
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&x);
			sum+=x;
		}
		int temp = 0;
		for(int i = 1;i<=n;i++)
		{
			temp+=i;
		}
	//	printf("%d %d\n",temp,sum);
		if(n==1)
		{
			if(x%2==0)printf("WIN\n");
			else printf("LOSE\n");
		}
		else
		{
			sum -= temp;
			if(sum%2==0)printf("LOSE\n");
			else printf("WIN\n");
		}
	}
    return 0;
}
