#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,num,sumnum = 0,sumturn = 0;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&num);
			sumnum+=num;
			sumturn +=i;
		}

		if(((sumnum - sumturn)%2) == 0)
			printf("LOSE\n");
		else
			printf("WIN\n");

	}
	return 0;
}
