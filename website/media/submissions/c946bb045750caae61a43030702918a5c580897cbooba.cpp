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
map<int,LL> dp[11][16];
int wi[11], vi[11], fi[11], cwi[11], cvi[11];
int N, W;

LL big(LL a, LL b) {
	return a>b?a:b;
}

LL go(int p, int n, int w) {
	if(p==N) return 0;
	if(w<=wi[p]*n) return NINF;
	if(dp[p][n].count(w)) return dp[p][n][w];
	int nn = n;
	if(nn>fi[p]) nn = fi[p];
	LL ret = 0;
	REP(i,nn+1) {
		ret = big(ret,go(p+1,15,w-wi[p]*i)+vi[p]*i);
	}
	return dp[p][n][w] = ret;
}


int main (int argc, char const* argv[]) {
	
	int t = GI;
	while(t--) {
		N = GI, W = GI;
		REP(i,N) wi[i]=GI, vi[i]=GI, fi[i]=GI;
/*		vector<three> vv;
		REP(i,N) vv.pb(make_pair(wi[i],make_pair(vi[i],fi[i])));
		sort(vv.begin(),vv.end());
		reverse(vv.begin(),vv.end());
		REP(i,N) wi[i] = vv[i].first, vi[i] = vv[i].second.first, fi[i] = vv[i].second.second;
*/
		printf("%lld\n",go(0,15,W));
	}
	
	return 0;
}

