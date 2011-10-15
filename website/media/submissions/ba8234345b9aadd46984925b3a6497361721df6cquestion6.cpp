# include<iostream>
# include<stdio.h>
# include<string.h>
using namespace std;
int main()
{
	int t,n,s,st,nol,i,j,count=0,no=0,p,c;
	char ori[500000],sub[500000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",ori);
		//printf("%s\n",ori);
		scanf("%d",&st);
		while(st--)
		{
			scanf("%d %d",&s,&nol);
			for(i=0,j=s,c=0;c<nol;i++,j++,c++)
				sub[i]=ori[j];
			//printf("%s\n",sub);
			for(i=0;i<n;i++)
			{
				for(j=0,p=i;j<nol;j++,p++)
				{
					if(ori[p]==sub[j])
					{
						no=no+1;
					}
					else
						break;
				}
				//printf("%d\n",no);
				if(no==nol)
				{
					count=count+1;
				}
				no=0;
			}
			printf("%d\n",count);
			count=0;
		}
	}
	return(0);
}
