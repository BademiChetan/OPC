#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)

inline int getint() { int x; scanf("%d",&x); return x; }

// Powered By TimoAI 2.2

int N;
int cache[128][128];
int calc(int odd,int even) {
	int &ret=cache[odd][even];
	if(ret>=0) return ret;
	if(odd+even==1) {
		if(odd) return ret=1;
		else return ret=2;
	}
	int turn = (N+1) - (odd + even);
	turn %= 2;
	// kalo turn = 1 (giliran player 1)
	if(turn==1) {
		// odd + odd
		if(odd>=2 && calc(odd-1,even)==1) return ret=1;
		// odd + even
		if(odd>=1 && even>=1 && calc(odd-1,even)==1) return ret=1;
		// even + even
		if(even>=2 && calc(odd+1,even-2)==1) return ret=1;
		return ret=2;
	}else {
		// odd + odd
		if(odd>=2 && calc(odd-2,even+1)==2) return ret=2;
		// odd + even
		if(odd>=1 && even>=1 && calc(odd-1,even)==2) return ret=2;
		// even + even
		if(even>=2 && calc(odd,even-1)==2) return ret=2;
		return ret=1;
	}

}
int main() {
	REP(nc,getint()) {
		N = getint();
		int odd = 0;
		int even = 0;
		REP(i,N) {
			int x = getint();
			if(x&1) odd++;
			else even++;
		}
		REP(a,128) REP(b,128) cache[a][b] = -1;
		if(calc(odd,even)==1) puts("WIN");
		else puts("LOSE");
	}
	return 0;
}
