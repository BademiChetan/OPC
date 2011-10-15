#include<stdio.h>
int main()
{	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{	scanf("%d%d",&a,&b);
		if(a<b){c=a;a=b;b=c;}
		if(a%2==0)printf("%d\n",a+b);
		else printf("%d\n",a-b);
	}
	return 0;
}
