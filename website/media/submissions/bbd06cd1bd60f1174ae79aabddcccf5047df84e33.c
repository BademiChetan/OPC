#include<stdio.h>
int main()
{
	int t,n,a[100],oc,ec;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		oc = 0; ec =0;
		while(n--)
		{
			if(n%2)
				oc++;
			else
				ec++;
		}
		if(ec>oc)
			printf("WIN\n");
		else
			printf("LOSE\n");
			
	}
	return 0;
}
