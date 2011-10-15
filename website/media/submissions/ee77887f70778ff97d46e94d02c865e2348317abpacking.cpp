/* AntiThesis, IIIT-Hyderabad */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

int N, W, w[22], v[22], f[22];
int ans;

map<int,int> M1, M2;

void solve1(int x,int y)
{
	
	M1[0]=0;
	
	int c=0,p=1;
	
	REP(i,N) 
		for(int j=1,s=0;j<=f[i];s+=j,j<<=1)
		{
			int k = j;
			if(s+j>f[i]) k = f[i] - (j-1);
			int wt = w[i]*k, val = v[i]*k;
			c^=1; p^=1;
			
			for(map<int,int>::reverse_iterator it = M1.rbegin();it!=M1.rend();it++)
			{
				int cwt = wt + it->F, cval = val + it->S;
				if(cwt>W) continue;
				if(!M1.count(cwt)) M1[cwt] = cval;
				else if(M1[cwt]<cval) M1[cwt] = cval;
				ans=max(ans,cval);
			}
		}
}

void solve2(int x,int y)
{
	
	M2[0]=0;
	
	int c=0,p=1;
	
	FOR(i,x,y)
		for(int j=1,s=0;j<=f[i];s+=j,j<<=1)
		{
			int k = j;
			if(s+j>f[i]) k = f[i] - (j-1);
			int wt = w[i]*k, val = v[i]*k;
			c^=1; p^=1;
			
			for(map<int,int>::reverse_iterator it = M2.rbegin();it!=M2.rend();it++)
			{
				int cwt = wt + it->F, cval = val + it->S;
				if(cwt>W) continue;
				if(!M2.count(cwt)) M2[cwt] = cval;
				else if(M2[cwt]<cval) M2[cwt] = cval;
				ans=max(ans,cval);
			}
		}

}



int main()
{
	for(int t=SI;t--;)
	{
		N = SI; W = SI;	
		REP(i,N) w[i]=SI, v[i]=SI, f[i]=SI;
		ans = 0;
		M1.clear(); M2.clear();
		
		if(N<5)
		{
			solve1(0,N); 
			printf("%d\n",ans);
			continue;
		}

		int n1 = N/2;

		solve1(0,n1+1);
		solve2(n1+1,N);

		map<int,int>::reverse_iterator it1 = M1.rbegin();
		map<int,int>::iterator it2 = M2.begin();
		int maxSoFar = 0;

		for(;it1!=M1.rend();it1++)
		{
			while(it2!=M2.end() && (it2->F)+(it1->F) <= W) maxSoFar=max(maxSoFar,it2->S), it2++;
			if( (it2!=M2.end()) && (it1->F)+(it2->F) <= W) ans = max(ans,(it1->S)+maxSoFar);
		}

		printf("%d\n",ans);
	}

	return 0;
}
