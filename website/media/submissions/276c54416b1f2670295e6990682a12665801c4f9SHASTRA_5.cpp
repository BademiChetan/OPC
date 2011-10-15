#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long LL;

int main() {
    int ntc;
    scanf("%d", &ntc);
    while( ntc-- ) {
        int N;
        LL W;
        scanf("%d %lld", &N, &W);
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
        LL ans = -1000000LL;
        for( int i=0; i<Lsize; i++ ) {
            for( int k=0; k<Rsize; k++ ) {
                if ( sumsL[i].first + sumsR[k].first <= W ) {
                    ans = max( ans, sumsL[i].second + sumsR[k].second );
                }
            }
        }
        printf("%lld\n", ans );
    }
    return 0;
}
