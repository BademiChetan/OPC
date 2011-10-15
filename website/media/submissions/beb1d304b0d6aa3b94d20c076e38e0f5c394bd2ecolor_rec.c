#include <stdio.h>
int color(int i, int j)
{
	if(i==1 && j==1)
		return 1;
	int max;
	int r;
	if(i>j)
		max=i;
	else
		max=j;
	int pow=1;
	while(pow<max)
		pow*=2;
	int p=pow/2;
	if(i>p && j>p)
		r=color(i-p,j-p);
	else if(i>p && j<=p)
		r=p+color(i-p,j);
	else if(i<=p && j<=p)
		r=color(i,j);
	else
		r=p+color(i,j-p);
	return r;
}
int main()
{
	int N,count;
	int ans[10000];//size
	scanf("%d",&N);
	for(count=0;count<N;count++)
	{
		//code
		int i,j;
		scanf("%d %d",&i,&j);
		i++;
		j++;
		int c=color(i,j)-1;
		ans[count]=c;//enter ans
	}
	for(count=0;count<N;count++)
	{
		printf("%d\n",ans[count]);
	}
	return 0;
}
