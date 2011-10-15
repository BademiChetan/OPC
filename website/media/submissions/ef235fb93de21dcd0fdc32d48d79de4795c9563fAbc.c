


#include<stdio.h>

int call(int x,int y)
{
	int ans=0;
	int t;
	t=x/2;
	ans=ans+t;
	t=y/2;
	ans=ans+t;
	ans=ans*2;

	if((x+y)%2!=0)
		ans=ans+1;

	if(ans==(x+y)){ans=1;}
	return ans;

}

int main(void)
{
	int t,x,y;

	scanf("%d",&t);


	while(t)
	{
		scanf("%d",&x);
		scanf("%d",&y);

		printf("%d",call(x,y));

		printf("\n");
		t--;

	}
    return 0;

}