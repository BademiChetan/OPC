#include<stdio.h>

int fac(int num)
{	
	if(num==1)
		return 4;
	else
		return(fac(num-1)*fac(num-1));
}
int main()
{
	int T,a[1000][2],i;
	scanf("%d",&T);
		for(i=0;i<T;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(i=0;i<T;i++)
	printf("%d\n",fac(a[i][0])%a[i][1]);
return 0;	
}
