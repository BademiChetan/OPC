#include <cstdio>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b) for(int (i)=(a),_n=(b);(i)<=_n;(i)++)
#define FORD(i,a,b) for(int (i)=(a),_n=(b);(i)>=_n;(i)--)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

int n, w;
int wi[15], vi[15], fi[15];
int best[15];
int ans;

void f(int x, int pay, int val) {
	ans = max(ans,val);
	if ( val + best[x] <= ans ) return;
	if ( x == n ) return;
	FORD(i,fi[x],0) if ( pay + i*wi[x] <= w )
		f(x+1,pay+i*wi[x],val+i*vi[x]);
}

int main()
{
	int T;
	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d", &n, &w );
		REP(i,n) scanf( "%d %d %d", &wi[i], &vi[i], &fi[i] );
		REP(i,n) REP(j,n-1) if ( vi[j] < vi[j+1] )
			swap(wi[j],wi[j+1]), swap(vi[j],vi[j+1]), swap(fi[j],fi[j+1]);

		best[n] = 0;
		FORD(i,n-1,0) best[i] = best[i+1] + fi[i] * vi[i];

		ans = 0;
		f(0,0,0);
		printf( "%d\n", ans );
	}
	return 0;
}
