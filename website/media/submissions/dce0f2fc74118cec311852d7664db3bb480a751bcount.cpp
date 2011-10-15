#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char kal[50005];
int p;
int hitung(int a, int b)
{
	int jum = 0;
	for(int i=0;i<p;i++)
	{
		if(i+b>p)break;
		if(kal[i]==kal[a])
		{
			int flag = 1;
			int temp = i+1;
			for(int j=a+1;j<a+b;j++)
			{
				if(kal[temp]==kal[j])temp++;
				else 
				{
					flag=0;
					break;
				}
			}
			jum+=flag;
		}
	}
	return jum;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	
		scanf("%d",&p);
		getchar();
		gets(kal);
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			printf("%d\n",hitung(a,b));
		}
	}
	return 0;
}
