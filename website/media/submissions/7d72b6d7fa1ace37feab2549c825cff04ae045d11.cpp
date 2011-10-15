#include <cstdio>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b) for(int (i)=(a),_n=(b);(i)<=_n;(i)++)
#define FORD(i,a,b) for(int (i)=(a),_n=(b);(i)>=_n;(i)--)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)


int main()
{
	int T;
	scanf( "%d", &T );
	while ( T-- ) {
		int r, c;
		scanf( "%d %d", &r, &c );
		int L = c, R = c, pos = c;
		FORD(i,20,0) if ( r & (1 << i) ) {
			if ( pos & (1 << i) ) pos -= (1 << i);
			else pos += (1 << i);
			r &= ~(1 << i);
		}
		printf( "%d\n", pos );
	}
	return 0;
}
