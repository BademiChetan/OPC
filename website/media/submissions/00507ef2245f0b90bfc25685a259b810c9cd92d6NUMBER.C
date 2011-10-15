#include<stdio.h>
int main()
{
	int n,a,b,t=1,arr[100],i;


		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			arr[i]=i+1;
			printf("%d\t",arr[i]);
		}
		scanf("%d %d",&a,&b);
		if(t==1)
		{
			a=a+b-t;
			b=a;
		}
		for(t=1;t<=n/2;t++)
		{

		}
		printf("%d",a);
	return 0;
}