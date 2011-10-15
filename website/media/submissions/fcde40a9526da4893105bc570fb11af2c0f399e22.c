#include<stdio.h>
void main()
{
	int i,j,k,n,a,b,c,d=1;
	scanf("%d",&n);
	while(n--)
	{scanf("%d  %d",&a,&b);
		a%=b;
		k=2;
for(i=0;i<a;i++)
	k=k*k;
	printf("%d\n",k);
	}
}

