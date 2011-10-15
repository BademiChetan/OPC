#include<stdio.h>

int fac(int num, int k)
{	
	if(num==1)
		return 4;
	else
		return(fac(num-1,k)*fac(num-1,k))%k;
}
int main()
{
	int T,i;
	int a[1000][2];
	scanf("%d",&T);
		for(i=0;i<T;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(i=0;i<T;i++)
	printf("%d\n",fac(a[i][0],a[i][1]));
return 0;	
}
