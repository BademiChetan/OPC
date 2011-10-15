#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long LL;

vector< pair< LL,LL > > v;
LL ct[20];

LL solve( int idx, LL W ) {
    if ( idx < 0) return 0;
    if ( W < v[idx].first ) return solve( idx-1, W);
    LL ans = solve( idx-1, W );
    for(int i=1; LL(i) <= ct[idx] && (v[idx].first*LL(i)) <= W; i++ ) {
        ans = max( ans, solve( idx-1, W-(v[idx].first*LL(i)) ) + (LL(i)*v[idx].second) );
    }
    return ans;
}

int main() {
    int ntc;
    scanf("%d", &ntc);
    while( ntc-- ) {
        int N;
        LL W;
        scanf("%d %lld", &N, &W);
        for( int i=0; i<N; i++ ) {
            LL Wi, Vi, Fi;
            scanf("%lld %lld %lld", &Wi, &Vi, &ct[i]);
            v.push_back( make_pair( Wi, Vi ) );
        }
        printf("%lld\n", solve( v.size()-1, W ) );
        /*
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
        */
    }
    return 0;
}
