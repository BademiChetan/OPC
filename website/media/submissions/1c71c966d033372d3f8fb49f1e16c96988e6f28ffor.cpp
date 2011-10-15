#include<cstdio>
using namespace std;

int res(int n,int k)
{
	if(n==0)
	return 1;
	else
	return (2*res(n-1,k))%k;
}

int main()
{
int res(int,int);
int t,i,n,k;
scanf("%d",&t);
int out[t];
for(i=0;i<t;i++)
{
scanf("%d %d",&n,&k);
out[i]=res(2*n,k);
}
for(i=0;i<t;i++)
printf("%d\n",out[i]);
}
