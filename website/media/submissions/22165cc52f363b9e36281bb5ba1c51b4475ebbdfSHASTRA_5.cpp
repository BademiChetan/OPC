#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long LL;

int main() {
    int ntc;
    scanf("%d", &ntc);
    while( ntc-- ) {
        int N, W;
        scanf("%d %d", &N, &W);
        vector< pair< LL,LL > > v;
        for( int i=0; i<N; i++ ) {
            LL Wi, Vi, Fi;
            scanf("%lld %lld %lld", &Wi, &Vi, &Fi);
            v.push_back( make_pair( Fi*Wi, Fi*Vi ) );
        }
        int n = v.size();
        int Lsize = 1 << (n/2), Rsize = 1 << ( n - n/2 );
        pair<LL, LL> sumsL[Lsize+3], sumsR[Rsize+3];

        for (int i = 0; i < Lsize; ++i) {
            sumsL[i].first = sumsL[i].second = 0;
            for (int j = 0; j < n / 2; ++j) {
                if ((i & (1 << j)) > 0) {
                    sumsL[i].first += v[j].first, sumsL[i].second += v[j].second;
                }
            }
        }
        for (int i = 0; i < Rsize; ++i) {
            sumsR[i].first = sumsR[i].second = 0;
            for (int j = 0; j < n - n / 2; ++j) {
                if ((i & (1 << j)) > 0) {
                    sumsR[i].first += v[j + n / 2].first, sumsR[i].second += v[j + n/2].second;
                }
            }
        }
        
        sort( sumsL, sumsL+Lsize );
        sort( sumsR, sumsR+Rsize );
        LL ans = 0LL;
        int L = 0, R = Rsize-1;
        while( L < Lsize && R >= 0 ) {
            if ( sumsL[L].first + sumsR[R].first <= W ) {
                ans = max( ans, sumsL[L].second + sumsR[R].second );
                L++;
            } else R--;
        }
        printf("%lld\n", ans );
    }
    return 0;
}
