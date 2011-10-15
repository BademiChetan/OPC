#include<stdio.h>
#include<map>
#include<vector>
using namespace std;


int funct(vector<vector<int> >&a,int p,int W,map<int, map<int,int> >&table)
{
	if(table[p][W]!=0)return table[p][W];
	if(W<0)
	return -1;
	if (p>a.size()-1)return 0;
	
	int val1=funct(a,p+1,W-a[p][0],table)+a[p][1];
	int val2=funct(a,p+1,W,table);
	int ret= (val1>val2)?val1:val2;
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
		map<int,map<int,int> >table;
		printf("%d\n",funct(a,0,W,table));
	}
	return 0;
}
