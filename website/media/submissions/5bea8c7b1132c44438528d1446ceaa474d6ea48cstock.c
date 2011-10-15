#include <stdio.h>
#include <math.h>

int power(int n)
{
	if(n==1)
		return 2;

	return pow(2,power(n-1));
}

void doit(int a[],int i)
{
	int days,divisor,b;
	
	scanf("%d",&days);
	
	scanf("%d",&divisor);
	
	b=power(days+1);
	
	a[i]=b%divisor;
	
	return;
}

int main()
{
	int cases,i=0,a[1000];
	
	scanf("%d",&cases);
	
	for(i=0;i<cases;i++)
		doit(a,i);
		
	for(i=0;i<cases;i++)
		printf("%d\n",a[i]);
		
	return 0;
}