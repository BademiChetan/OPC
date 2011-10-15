
/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

vector < PI > vec1;
vector < PI > vec2;
vector < PI > vec3;
vector < PI > vec4;
int n,f[100],c[100],v[100],w;
void brute1(int cur,int cost,int value)
{
	int i;
	if(cost>w)
		return;
	if(cur==(n+1)/2)
	{
		if(cost>w)
			return;
		PI temp(cost,value);
		//		printf("%d %d\n",cost,value);
		vec1.push_back(temp);
		return;
	}
	for(i=0;i<=f[cur];i++)
	{
		brute1(cur+1,cost+i*c[cur],value+i*v[cur]);
	}
}
void brute2(int cur,int cost,int value)
{
	int i;
	if(cost>w)
		return;
	if(cur==(n))
	{
		if(cost>w)
			return;
		PI temp(cost,value);
		//		printf("%d %d\n",cost,value);
		vec2.push_back(temp);
		return;
	}
	for(i=0;i<=f[cur];i++)
	{
		brute2(cur+1,cost+i*c[cur],value+i*v[cur]);
	}
}
int binary(int curwei)
{
	int req,high,low,mid;
	if(vec4.size()==0)
		return 0;
	req=w-curwei;
	if(vec4.size()>0&&vec4[0].first>req)
		return 0;
	low=0;
	high=vec4.size();
	while(low<high)
	{
		mid=(low+high)/2;
		if(vec4[mid].first==req)
		{
			return vec4[mid].second;
		}
		if(vec4[mid].first>req)
		{
			high=mid-1;
		}
		else
		{
			if(low==mid)
				break;
			low=mid;
		}
	}
	if((low+1)<vec4.size()&&vec4[low+1].first<=req)
		low++;
	return vec4[low].second;
}
int binary2(int curwei)
{
	int req,high,low,mid;
	if(vec3.size()==0)
		return 0;
	req=w-curwei;
	if(vec3.size()>0&&vec3[0].first>req)
		return 0;
	low=0;
	high=vec3.size();
	while(low<high)
	{
		mid=(low+high)/2;
		if(vec3[mid].first==req)
		{
			return vec3[mid].second;
		}
		if(vec3[mid].first>req)
		{
			high=mid-1;
		}
		else
		{
			if(low==mid)
				break;
			low=mid;
		}
	}
	if((low+1)!=vec3.size()-1&&vec3[low+1].first<=req)
		low++;
	return vec3[low].second;
}
int main()
{
	int t,i,n1,n2,cur,ans;
	scanf("%d",&t);
	while(t--)
	{
		vec1.clear();
		vec2.clear();
		vec3.clear();
		vec4.clear();

		scanf("%d%d",&n,&w);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&c[i],&v[i],&f[i]);
		}

		brute1(0,0,0);
		brute2((n+1)/2,0,0);
		sort(vec1.begin(),vec1.end());
		sort(vec2.begin(),vec2.end());
		n1=vec1.size();
		n2=vec2.size();
	/*	printf("%d\n",n1);
		for(i=0;i<n1;i++)
		{
			printf("%d %d\n",vec1[i].first,vec1[i].second);
		}
		printf("%d\n",n2);
		for(i=0;i<n2;i++)
		{
			printf("%d %d\n",vec2[i].first,vec2[i].second);
		}*/
		n1=vec1.size();
		cur=0;
		for(i=0;i<n1-1;i++)
		{
			if(vec1[i].first!=vec1[i+1].first&&vec1[i].second>cur)
			{
				vec3.push_back(vec1[i]);
				cur=vec1[i].second;
			}
		}
		if(n1>0&&vec1[n1-1].second>cur)
			vec3.push_back(vec1[n1-1]);
		n2=vec2.size();
		cur=0;
		for(i=0;i<n2-1;i++)
		{
			if(vec2[i].first!=vec2[i+1].first&&vec2[i].second>cur)
			{
				vec4.push_back(vec2[i]);
				cur=vec2[i].second;
			}
		}
		if(n2>0&&vec2[n2-1].second>cur)
			vec4.push_back(vec2[n2-1]);
		n1=vec3.size();
		n2=vec4.size();
			/*printf("%d\n",n1);
			for(i=0;i<n1;i++)
			{
			printf("%d %d\n",vec3[i].first,vec3[i].second);
			}
			printf("%d\n",n2);
			for(i=0;i<n2;i++)
			{
			printf("%d %d\n",vec4[i].first,vec4[i].second);
			}*/
		if(1)
		{
			ans=0;
			for(i=0;i<n1;i++)
			{
				cur=vec3[i].second+binary(vec3[i].first);
				if(ans<cur)
				{
					ans=cur;
				}
			}
		}
		else
		{
			ans=0;
			for(i=0;i<n2;i++)
			{
				cur=vec4[i].second+binary2(vec4[i].first);
				if(ans<cur)
				{
					ans=cur;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
