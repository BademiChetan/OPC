#include<stdio.h>
using namespace std;
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=y;
		printf("%d\n",ans-x);
	}
	return 0;
}
		