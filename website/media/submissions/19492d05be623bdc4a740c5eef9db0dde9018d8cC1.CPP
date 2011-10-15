#include<stdio.h>
int main()
{
	int t,i,a[100],n,turn,flag=0;
	scanf("%d",&t);
	while(t--)
	{
		turn=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
			for(i=0;i<(n-1);i++)
			{
				if(flag==2)
				{
					flag=0;
					turn++;
				}
				a[i+1]=a[i+1]+a[i]-turn;
				flag++;
			}
			if(a[i]%2==0)
				printf("LOSE");
			else
				printf("WIN");
	}
	return 0;
}