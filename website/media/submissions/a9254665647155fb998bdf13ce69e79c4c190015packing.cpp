#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define MP make_pair
#define ST first
#define ND second

typedef pair<int,int > PII; 
inline int getint() { int x; scanf("%d",&x); return x; }

// Powered By TimoAI 2.2

int cost[11];
int fun[11];
int freq[11];
PII dp1[1<<20];
PII dp2[1<<20];
int best;
int N;
int limit = 7;
map< int,int> cache;
int k;
int n1,n2;

void gen(PII *dp,int from,int to,int sumW,int sumF) {
	if(from==to) {
		dp[k++] = MP(sumW,sumF);
	}else {
		FOR(take,0,freq[from])
			gen(dp,from+1,to,sumW+cost[from]*take,sumF+fun[from]*take);
	}
}

int calc(int W) {
	k=0; gen(dp1,0,N/2,0,0); n1=k;
	k=0; gen(dp2,N/2,N,0,0); n2=k;
	sort(dp1,dp1+n1);
	sort(dp2,dp2+n2);
	FOR(i,1,n1-1) dp1[i].ND = max( dp1[i].ND, dp1[i-1].ND);
	FOR(i,1,n2-1) dp2[i].ND = max( dp2[i].ND, dp2[i-1].ND);
	int i=0;
	int j=n2-1;
	int best = 0;
	while(i<n1 && j>=0) {
		int sumW = dp1[i].ST + dp2[j].ST;
		int sumF = dp1[i].ND + dp2[j].ND;
		if(sumW  <= W) {
			i++;
			best=max(best,sumF);
		}else {
			j--;
		}
	}
	return best;
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
		cout<<calc(W)<<endl;
	}
	return 0;
}
