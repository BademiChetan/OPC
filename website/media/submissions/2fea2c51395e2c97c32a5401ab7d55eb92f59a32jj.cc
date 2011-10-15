#include<stdio.h>
int main()
{
int t;
long n[1000],k[1000];
long m=2;
//printf("enter the no.of test cases");
scanf("%d",&t);
//printf("enter the value of n and k");
for(int i=0; i<t;i++)
	{
	scanf("%ld %ld", &n[i],&k[i]);
		
	}
for(int z=0;z<t;z++)
	{
	m=2;
	for(long i=1;i<=n[z];i++)
		{
		m=m*m;
		m=m%k[z];
		}
	
	printf("%ld\n",m);
	}
return(0);
}
