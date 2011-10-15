#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int T,i,c,d,temp,p;
	long long sum;
	int x,y,M[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		sum=0;
		if(x>y)
		{
			temp=x;
			x=y;
			y=temp;
		}
		for(i=9;i>=0;i--)
		{
			p=pow(4,i);
			c=(x/p);
			d=(y/p);
			sum+=(M[c][d]*p);
			x=x%p;
			y=y%p;
		}
		printf("%Ld\n",sum);
	}
}			
