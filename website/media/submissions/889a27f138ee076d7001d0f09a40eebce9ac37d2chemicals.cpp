#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define SI ({int x;scanf("%d",&x);x;})
#define PB(x) push_back(x)
#define MXN 11
#define MXW 10000007

int N,B;
int dp[MXW], cnt[MXN];
int val[MXN];
int cost[MXN];

void solve()
{
		for(int t=0;t<N;t++)
		{
			for(int j=1,s=0;j<=cnt[t];s+=j,j<<=1) 
			{
				int k = j;
				if(s+j>cnt[t]) k = cnt[t] - (j-1);
				int w = k*cost[t], c = k*val[t];
				for(int i=B;i>=w;i--) dp[i] = max(dp[i],dp[i-w]+c);
			}
		}

		cout<<dp[B]<<endl;
}

int main()
{
	int t = SI;
	while(t-- >0)
	{	
		N = SI;
		B = SI;
		for(int i=0;i<N;i++)
		{
			cost[i] = SI;
			val[i] = SI;
			cnt[i] = SI;
		}
		solve();
	}
	return 0;
}
