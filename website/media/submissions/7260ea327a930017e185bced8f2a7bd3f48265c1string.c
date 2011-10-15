#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* subString(char* s,int k,int b)
{
	char *temp;
	temp=malloc(sizeof(int)*b+2);
	int i,l=0;
	for(i=k;i<b+k;i++)
	{
		temp[l]=s[i];
		l++;
	}
	return temp;
}
int main()
{
	char *str,*temp;
	int *test;
	int *qu;
	int n,N,q,l=0;
	int a,b,k,j,i;
	int count=0;
	scanf("%d",&n);
	test=malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&N);
		str=malloc(sizeof(int)*N);
		scanf("%s",str);
		scanf("%d",&q);
		qu=malloc(sizeof(int)*q);
		for(j=0;j<q;j++)
		{
			count=0;
			l=0;
			scanf("%d %d",&a,&b);
			temp=malloc(sizeof(int)*b+1);
			if(b==1)
				temp[0]=str[a];
			for(k=a;k<b;k++)
			{
				temp[l]=str[k];
				l++;
			}
			for(k=0;k<N;k++)
			{
				if(strcmp(subString(str,k,b),temp)==0)
					count++;
			}
			qu[j]=count;
		}
	}
	for(i=0;i<q;i++)
		printf("%d\n",qu[i]);
	return 0;
}
