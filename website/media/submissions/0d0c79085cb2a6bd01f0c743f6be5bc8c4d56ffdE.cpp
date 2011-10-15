#include<stdio.h>
#include<map>
using namespace std;
map<pair<int,int>,int> Map;
int n;
int arr[10][3];
int counter;
int maxi(int a,int b)
{
	if(a>b)return a;
	return b;
}
int find(int item,int budget)
{
	if(item==n)
		return 0;
	if(budget==0)return 0;
	if(budget<0)return -1000000000;
	int mp= Map[make_pair(item,budget)];
	if(mp) return mp;
	
	int max=0;
	for(int i=0;i<=arr[item][2];i++)
		max=maxi(max,arr[item][1]*i+find(item+1,budget-arr[item][0]*i));
	Map[make_pair(item,budget)] = max;
	return max;

}
int main()
{
	int t,bud;
	scanf("%d",&t);
	
	while(t--)
	{
		
		Map.clear();
		scanf("%d",&n);
		scanf("%d",&bud);
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				scanf("%d",&arr[i][j]);
		printf("%d\n",find(0,bud));
		
	}
	
	return 0;
}