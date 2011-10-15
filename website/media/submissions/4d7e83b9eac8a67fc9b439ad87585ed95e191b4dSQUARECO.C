#include<stdio.h>
int main()
{
	int i,n,r,t,e;
	int x,y,a[10000],m;
	r=scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	t=scanf("%d",&x);
	e=scanf("%d",&y);
	m=(x>=y)?x:y;
	if(y-x>=0)
	a[i]=y-x;
	else
	a[i]=m+(y-x);
	}
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	return 1;
}