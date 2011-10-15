#include<stdio.h>
#include<stdlib.h>
int color(int ,int,int ,int);
int **val;
int main()
{
	int i,t,x,y,r1,r2,value;
	val=(int **)calloc(2,sizeof(int));
	val[0]=(int *)calloc(2,sizeof(int));
	val[1]=(int *)calloc(2,sizeof(int));
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		r1=x%2;
		r2=y%2;
		value=color(x,y,r1,r2);
		printf("%d\n",value);
	}
	return 0;
}

int color(int x,int y,int rem1,int rem2)
{
	int r1,r2,value;
	if(x==0 && y==0)
		return val[rem1][rem2];
	r1=x%2;
	r2=y%2;
	value=color(x/2,y/2,r1,r2);
	if(r1!=r2)
		return 2*value+1;
	else
		return 2*value;
}

