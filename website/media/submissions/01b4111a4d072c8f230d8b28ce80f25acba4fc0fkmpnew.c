#include<stdio.h>
#include<string.h>
void compute_prefix(char p[51000],int pi[51000])
{
	int m,q,k;
	m=strlen(p);
	k=0;
	pi[1]=0;
	for(q=2;q<=m;q++)
	{
		while(k>0 && p[k]!=p[q-1])
			k=pi[k];
		if(p[k]==p[q-1])
			k=k+1;
		pi[q]=k;
	}
}



int main()
{
	char p[51000],t[51000];
	int i,pi[51000],m,n,q,count=0,cnt,size,test,loop,times;
	scanf("%d",&test);
	for(cnt=0;cnt<test;cnt++)
	{
		scanf("%d",&size);
		scanf("%s",t);
		scanf("%d",&times);
		for(loop=0;loop<times;loop++)
		{
			count=0;
			scanf("%d%d",&m,&n);
			for(i=m;i<=m+n-1;i++)
				p[i-m]=t[i];
			p[i-m]='\0';
			compute_prefix(p,pi);
			m=strlen(p);
			n=strlen(t);
			q=0;
			for(i=1;i<=n;i++)
			{
				while(q>0 && p[q]!=t[i-1])
					q=pi[q];
				if(p[q]==t[i-1])
					q=q+1;
				if(q==m)
				{
					count++;
					q=pi[q];
				}
			}
			printf("%d\n",count);
		}
	}
	return 0;
}



