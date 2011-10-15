#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

inline int getint() { int x; scanf("%d",&x); return x; }

// Powered By TimoAI 2.2

int cost[10];
int fun[10];
int freq[10];
int best;
int N;
map<int,int> cache[10];

int calc(int idx,int W) {
	if(idx==N) return 0;
	bool caching = idx>=6;
	if(caching) {
		if(cache[idx].count(W))
			return cache[idx][W];
	}
	int ret=0;
	FOR(take,0,freq[idx])
		if(W-cost[idx]*take>=0)
			ret=max(ret,calc(idx+1,W-cost[idx]*take)+fun[idx]*take);
		else
			break;
	if(caching) cache[idx][W]=ret;
	return ret;
}

int main() {
	REP(nc,getint()) {
		N=getint();
		int W=getint();
		REP(i,N) {
			cost[i]=getint();
			fun[i]=getint();
			freq[i]=getint();
		}
		REP(i,N) cache[i].clear();
		cout<<calc(0,W)<<endl;
	}
	return 0;
}
