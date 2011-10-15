#include <map>

#include <cstring>
#include <cstdio>
#define sz size()
#define pb push_back
#define _(x,a) memset(x,a,sizeof(x))
#define LET(x,a) typeof(a) x(a)
#define FOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define LL long long
#define NINF 1LL<<63
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})

using namespace std;

typedef pair<int,pair<int,int> > three;
map<LL,LL> dp[155];
LL wi[155], vi[155], fi[155], cwi[155], cvi[155];
LL N, W;

LL big(LL a, LL b) {
	return a>b?a:b;
}

LL go(LL p, LL w) {
	if(p<0) return 0;
	if(cwi[p]<=w) return cvi[p];
	if(dp[p].count(w)) return dp[p][w];

	return dp[p][w] = big(go(p-1,w),go(p-1,w-wi[p]));
}


int main (int argc, char const* argv[]) {
	
	int t = GI;
	while(t--) {
		N = GI, W = GI;
		int ptr = 0;
		REP(i,N) {
			int w = GI, v = GI, f = GI;
			REP(j,f) wi[ptr] = w, vi[ptr++] = v;
		}
		cwi[0] = wi[0]; cvi[0] = vi[0];
		FOR(i,1,ptr) cwi[i] = cwi[i-1]+wi[i], cvi[i] = cvi[i-1]+vi[i];
		
		printf("%lld\n",go(ptr-1,W));
	}
	
	return 0;
}

