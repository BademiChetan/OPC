#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)

inline int getint() { int x; scanf("%d",&x); return x; }

// Powered By TimoAI 2.2

int calc(int r,int c) {
	if(r<=1 && c<=1) return (r+c)%2;
	int dr = r & 1;
	int dc = c & 1;
	return 2*calc(r/2,c/2)+ ((dr+dc)%2);
}

int main() {
	REP(nc,getint()) {
		int r = getint();
		int c = getint();
		printf("%d\n",calc(r,c));
	}
	return 0;
}
