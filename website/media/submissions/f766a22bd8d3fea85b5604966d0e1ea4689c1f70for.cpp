#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
int t,i,j;
long int n,k; 
scanf("%d",&t);
int out[t];
for(i=0;i<t;i++)
{
scanf("%ld %ld",&n,&k);
out[i]=2;
for(j=0;j<n;j++)
{
	out[i]=(out[i]*out[i])%k;
	if(out[i]==1||out[i]==0)
	break;
}}
	
for(i=0;i<t;i++)
printf("%d\n",out[i]);

return 0;
}
