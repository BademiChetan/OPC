#include<stdio.h>
int main()
{
	int i,n;
	long int x,y,a[10000],m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%ld",&x);
	scanf("%ld",&y);
	m=(x>=y)?x:y;
	if(y-x>=0)
	a[i]=y-x;
	else
	a[i]=m+(y-x);
	}
	for(i=0;i<n;i++)
	printf("%ld\n",a[i]);
	return 0;
}