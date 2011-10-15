#include <stdio.h>

int divide_conquer(int x,int n)
{
	int temp;
	
	if(n==1)
	{
		return x;
	}

	if(n%2==0)
	{
		temp=divide_conquer(x,n/2);
		
		return temp*temp;
	}
	
	else
	{
		temp=divide_conquer(x,(n-1)/2);
		
		return temp*temp*x;
	}
}

int power(int n)
{
	if(n==1)
		return 2;

	return divide_conquer(2,power(n-1));
}

void doit(int a[],int i)
{
	int days,divisor;
	long b;
	
	scanf("%d",&days);
	
	scanf("%d",&divisor);
	
	b=divide_conquer(2,divide_conquer(2,days));
	
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