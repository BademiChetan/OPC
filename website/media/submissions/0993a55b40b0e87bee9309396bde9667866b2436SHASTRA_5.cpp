#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int ntc;
    scanf("%d", &ntc);
    while( ntc-- ) {
        int N, W;
        scanf("%d %d", &N, &W);
        vector< pair< int,int > > v;
        for( int i=0; i<N; i++ ) {
            int Wi, Vi, Fi;
            scanf("%d %d %d", &Wi, &Vi, &Fi);
            v.push_back( make_pair( Fi*Wi, Fi*Vi ) );
        }
        
        int n = v.size();
        int Lsize = 1 << (n/2), Rsize = 1 << ( n - n/2 );
        pair<int, int> sumsL[Lsize+3], sumsR[Rsize+3];

        for (int i = 0; i < Lsize; ++i) {
            sumsL[i].first = sumsL[i].second = 0;
            for (int j = 0; j < n / 2; ++j) {
                if ((i & (1 << j)) > 0) {
                    sumsL[i].first += v[j].first, sumsL[i].second += v[j].second;
                }
            }
        }
        for (int i = 0; i < Rsize; ++i) {
            for (int j = 0; j < n - n / 2; ++j) {
                if ((i & (1 << j)) > 0) {
                    sumsR[i].first += v[j + n / 2].first, sumsR[i].second += v[j + n/2].second;
                }
            }
        }
        sort( sumsL, sumsL+Lsize );
        sort( sumsR, sumsR+Rsize );
        int ans = 0, L = 0, R = Rsize-1;
        while( L < Lsize && R >= 0 ) {
            if ( sumsL[L].first + sumsR[R].first <= W ) {
                ans = max( ans, sumsL[L].second + sumsR[R].second );
                L++;
            } else R--;
        }
        printf("%d\n", ans );
    }
    return 0;
}
