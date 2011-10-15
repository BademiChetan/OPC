#include <stdio.h>
static int a[50];
int n,sum=0,count=0,k[5];
void subset(int,int,int,int);
int main() {
int i,x,size[5],t,j;
scanf("%d",&t);
	j=0;
	while(j<2)
	{
		scanf("%d %d",&size[j],&k[j]);
		j++;
	}
	j=0;
	while(j<2)
	{
		x=0;
		while(x<size[j])
		{
			a[x] = x + 1;
			x++;
		}
		n = size[j];
		i=1;
		while(i<=n)
		{
			subset(0,0,i,k[j]);
			i++;
		}
		printf("%d\n",count+1);
		count=0;
		j++;
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
i=0;
while(i<n)  {
	if((a[i] % k) == 0)	{
	      count++;
	}
i++;
}
}
else
{
j=index;
while(j<n)
{
	i=start;
	while(i<index)	{
		sum += a[i];
		i++;
	}
	sum += a[j];
	if((sum % k) == 0)	{
	       count++;
	}
j++;
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
