#include<stdio.h>
int fun(int a,int b,int n)
{	if(a==b)return 0;
	if(b==0)return a;
	if(a<n/2&&b<n/2)return fun(a,b,n/2);
	if(b<n/2)	{a-=n/2;if(a<b)return (n/2)+fun(b,a,n/2);return (n/2)+fun(a,b,n/2);}
	a-=n/2;b-=n/2;
	if(a<b)return fun(b,a,n/2);
	return fun(a,b,n/2);
}
int main()
{	int t,a,b,c,o,p,min,max,i,res;
	scanf("%d",&t);
	while(t--)
	{	scanf("%d%d",&a,&b);
		if(a==b){printf("0\n");continue;}
		max=a>b?a:b;p=max;
		min=a<b?a:b;
		o=2;
		for(i=1;p/2;i++){p/=2;o*=2;}
		res=fun(max,min,o);
		printf("%d\n",res);
	}
    return 0;
}
