#include<stdio.h>
main()
{	char str[50000];
	int n,t;
	int q,m,k;
	int sum=0;
	int i,j,x,y,z;
	scanf("%d",&t);
	while(t--)
	{	scanf("%d",&n);
		scanf("%s",str);
		scanf("%d",&q);
		while(q--)
		{	scanf("%d%d",&m,&k);
			sum = 0;
			for(i=0;i<n;i++)
			{	if( str[i]==str[m])
				{	x=i;
					y=m;
					while(str[x]==str[y] && y<m+k)
					{	x++;
						y++;
					}
					if(y==m+k)
					{	sum++;
					}
				}
			}
			printf("\n%d",sum);
		}
	}
	return 0;
}
