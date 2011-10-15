#include<stdio.h>
#include<map>
#include<vector>
using namespace std;


long long funct(vector<vector<int> >&a,int p,int W,map<int, map<int,long long> >&table)
{
	if(W<0)return -1;
	if(table[p][W]!=0)return table[p][W];
	
	if (p==a.size())return 0;
	
	long long  val1=funct(a,p+1,W-a[p][0],table)+a[p][1];
	long long  val2=funct(a,p+1,W,table);
	long long  ret= (val1>val2)?val1:val2;
	table[p][W]=ret;
	return ret;
	
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,W;
		scanf("%d %d",&N,&W);
		vector<vector<int> >a;
		
		
		for(int i=0;i<N;i++)
		{
			int cost,value,num;
			scanf("%d %d %d",&cost,&value,&num);
			for(int j=0;j<num;j++)
			{
				vector<int>temp(2);
				temp[0]=cost;
				temp[1]=value;
				a.push_back(temp);
			}
		}
		map<int,map<int,long long > >table;
		printf("%lld\n",funct(a,0,W,table));
	}
	return 0;
}
