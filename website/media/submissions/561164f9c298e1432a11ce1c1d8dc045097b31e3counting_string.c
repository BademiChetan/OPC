#include<stdio.h>
#include<stdlib.h>

void main()
{
	int T;
	scanf("%d", &T);
	int i,flag=0;
	unsigned short int j,k,l,m,n,count=0;
	unsigned short int length;
	unsigned short int Q;
	unsigned short int M;
	unsigned short int K;
	unsigned short int result[T][50001];
	
	for(i=0;i<T;i++)
	{
		scanf("%hu",&length);
		char str[length];
	
		scanf("%s",&str);		
		scanf("%hu",&Q);
		result[i][0]=Q;
		for(j=0;j<Q;j++)
		{
			scanf("%hu %hu",&M,&K);
			if((M+K-1)>=length){("\n Error..."); exit(0);}
			l=M;
			char str1[l+1];
			for(k=0;k<K;k++)
			str1[k]=str[l++];
			for(m=0;m<(length-K+1);m++)
			{n=m;
				for(l=0;l<K;l++)
				{if(str[n++]!=str1[l]) {flag=1;break;}}
				if(flag==0) count++;
				flag=0;
			}
			result[i][j+1]=count;
			count=0;
		}
	}
	printf("Result is: \n");
	for(i=0;i<T;i++)
	{ printf("For Test Case %hu \n",i+1);
	for(j=1;j<=result[i][0];j++)
		printf("For Query %hu \t %hu \n",j,result[i][j]);
	printf("-------------------------------\n");	
	}
}
