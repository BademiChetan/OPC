#include<stdio.h>
main()
{
	int i,t,n,q,m,k,j,x,p,r,h;
	char text[50000];
	scanf("%d",&t);
	for(r=0;r<t;r++)
	{
		scanf("%d",&n);
		scanf(" %s",text);
		scanf("%d",&q);
		for(p=0;p<q;p++)
		{
			h=0;
			scanf("%d%d",&m,&k);
			for(i=0;i<n;i++)
			{
				x=0;
				if(text[i]==text[m])
				{
					for(j=0;j<k;j++)
					{
						if(text[i+j]==text[m+j]) x++;
						else break;
					}
				}
				if(x==k) h++;
			}
			printf("%d\n",h);
		}
	}
}
