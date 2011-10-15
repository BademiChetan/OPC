#include <stdio.h>
static int a[50];
int n,sum=0,count=0,k[5];
void subset(int,int,int,int);
int main() {
int i,x,size[5],t,j;
scanf("%d",&t);
	for(j=0;j<t;j++)	{
		scanf("%d %d",&size[j],&k[j]);
	}
	for(j=0;j<t;j++)	{
		for(x=0;x<size[j];x++)	{
			a[x] = x + 1;
		}
		n = size[j];
		for(i=1;i<=n;i++)	{
			subset(0,0,i,k[j]);
		}
		printf("%d\n",count+1);
		count=0;
	}
return 0;
}
void subset(int start,int index,int no_of_subset,int k)
{
int i,j;
sum=0;
if(index-start+1==no_of_subset)
{
if(no_of_subset==1)
{
for(i=0;i<n;i++)  {
	if((a[i] % k) == 0)	{
	      count++;
	}
}
}
else
{
for(j=index;j<n;j++)
{
	for(i=start;i<index;i++)	{
		sum += a[i];
	}
	sum += a[j];
	if((sum % k) == 0)	{
	       count++;
	}
}
if(start!=n-no_of_subset)
subset(start+1,start+1,no_of_subset,k);
}
}
else
{
subset(start,index+1,no_of_subset,k);
}
}
