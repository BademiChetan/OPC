#include<stdio.h>
#include<math.h>
int main()
    {
	int i,t,c;
	long a,b,p;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
			scanf("%d",&a);
			p=pow(4,a);
			scanf("%d",&b);
			c=p%b;
			printf("%d\n",c);
	}
	return 0;
    }