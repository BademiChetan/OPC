# include<iostream>
# include<stdio.h>
# include<string.h>
using namespace std;
int main(int argc,char *argv[])
{
	int t,n,s,st,nol,i,j,count=0,no=0,p,c;
	char ori[500000],sub[500000];
	FILE *fp=fopen(argv[1],"r");
	fscanf(fp,"%d",&t);
	while(t--)
	{
		fscanf(fp,"%d",&n);
		fscanf(fp,"%s",ori);
		//printf("%s\n",ori);
		fscanf(fp,"%d",&st);
		while(st--)
		{
			fscanf(fp,"%d %d",&s,&nol);
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
