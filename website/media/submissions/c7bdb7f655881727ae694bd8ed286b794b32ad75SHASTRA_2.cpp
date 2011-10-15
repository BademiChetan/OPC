#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

int memo[3][120][120];

int solve( int idx, int odd, int even ) {
    //printf(" >> %d %d %d\n", idx, odd, even );
    if ( memo[idx][odd][even] != -1 ) return memo[idx][odd][even];
    if ( odd + even == 1 ) return memo[idx][odd][even] = ( odd > 0 ) ? 1 : 0;
    int ret = ( idx%2==1 ) ? 0 : 1;
    if ( idx%2==1 ) {
        if ( odd > 1 ) ret = max( ret, solve( 0, odd-1, even ) );
        if ( odd > 0 && even > 0 ) ret = max( ret, solve(0, odd-1, even ));
        if ( even > 1 ) ret = max(ret, solve( 0, odd+1, even-2 ) );
    } else {
        if ( odd > 1 ) ret = min( ret, solve( 1, odd-2, even+1 ) );
        if ( odd > 0 && even > 0 ) ret = min( ret, solve( 1, odd, even-1 ) );
        if ( even > 1 ) ret = min(ret, solve( 1, odd, even-1 ) );
    }
    return memo[idx][odd][even] = ret;
}

int main() {
    int ntc;
    scanf("%d", &ntc);
    while( ntc-- ) {
        int N, odd = 0, even = 0;
        memset( memo, -1, sizeof(memo));
        scanf("%d", &N);
        for( int i=0, x; i<N; i++ ) {
            scanf("%d", &x);
            odd += ( x%2==1 ), even += ( x%2==0 );
        }
        puts( (solve( 1, odd, even ) == 0) ? "LOSE" : "WIN");
    }
    return 0;
}
