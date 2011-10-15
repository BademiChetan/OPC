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

int solve()
{
	map<int,int> M;
	
	M[0]=0;
	
	int c=0,p=1,ans=0;
	
	REP(i,N) 
		for(int j=1,s=0;j<=f[i];s+=j,j<<=1)
		{
			int k = j;
			if(s+j>f[i]) k = f[i] - (j-1);
			int wt = w[i]*k, val = v[i]*k;
			c^=1; p^=1;
			
			for(map<int,int>::reverse_iterator it = M.rbegin();it!=M.rend();it++)
			{
				int cwt = wt + it->F, cval = val + it->S;
				if(cwt>W) continue;
				if(!M.count(cwt)) M[cwt] = cval;
				else if(M[cwt]<cval) M[cwt] = cval;
				ans=max(ans,cval);
			}
		}

	M.clear();

	return ans;
}

int main()
{
	for(int t=SI;t--;)
	{
		N = SI; W = SI;	
		REP(i,N) w[i]=SI, v[i]=SI, f[i]=SI;
		printf("%d\n",solve());
	}

	return 0;
}