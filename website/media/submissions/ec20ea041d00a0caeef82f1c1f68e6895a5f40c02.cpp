#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b) for(int (i)=(a),_n=(b);(i)<=_n;(i)++)
#define FORD(i,a,b) for(int (i)=(a),_n=(b);(i)>=_n;(i)--)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

int dp[105][105][2];
int f(int n, int odd, int move) {
	if ( n == 1 ) return odd == 1 ? 1 : 2;
	if ( dp[n][odd][move] != -1 ) return dp[n][odd][move];
	int &ret = dp[n][odd][move];
	int even = n - odd;
	if ( move == 0 ) {
		ret = 2;
		if ( odd  >= 2 && f(n-1,odd-1,1) == 1 ) ret = 1;
		if ( even >= 2 && f(n-1,odd+1,1) == 1 ) ret = 1;
		if ( odd >= 1 && even >= 1 && f(n-1,odd-1,1) == 1 ) ret = 1;
	}
	else {
		ret = 1;
		if ( odd  >= 2 && f(n-1,odd-2,0) == 2 ) ret = 2;
		if ( even >= 2 && f(n-1,odd,0) == 2   ) ret = 2;
		if ( odd >= 1 && even >= 1 && f(n-1,odd,0) == 2 ) ret = 2;
	}
	return ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int T;
	scanf( "%d", &T );
	while ( T-- ) {
		int n, x, odd = 0;
		scanf( "%d", &n );
		REP(i,n) scanf( "%d", &x ), odd += (x & 1);
		puts( f(n,odd,0) == 1 ? "WIN" : "LOSE" );
	}
	return 0;
}
