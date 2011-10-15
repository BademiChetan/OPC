#include<stdio.h>
void main()
{
	int i,a,n,c=0,d=2;

	long int b,k,d;


	scanf("%d",&n);

	while(n--)
	{scanf("%d  %d",&a,&b);
		a%=b;
		k=2;
		if(a>c)
		{i=c;k=d;}
		else
		{c=0;k=2;}
		for(i=c;i<a;i++)
			k=k*k;
	printf("%d\n",k);
	c=i;
	d=k;
	
	}
}

