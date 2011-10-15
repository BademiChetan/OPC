#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

struct eqstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) == 0;
  }
};


hash_map< const char *, int, hash<const char*>, eqstr > memo;
vector< pair< int,int > > v;
int ct[20];

int solve( int idx, int W ) {
    char ns[30];
    sprintf( ns, "%d|%d", idx, W);
    if ( idx < 0) return 0;
    if ( memo.count( ns ) > 0 ) return memo[ ns ];
    if ( W < v[idx].first ) return memo[ ns ] = solve( idx-1, W);
    int ans = solve( idx-1, W );
    for(int i=1; i <= ct[idx] && (v[idx].first*i) <= W; i++ ) {
        int nx = solve( idx-1, W-(v[idx].first*i) ) + (i*v[idx].second);
        if ( nx < ans ) break;
        ans = max( ans, nx );
    }
    return memo[ ns ] = ans;
}

int main() {
    int ntc;
    scanf("%d", &ntc);
    while( ntc-- ) {
        int N, W;
        scanf("%d %d", &N, &W);
        v.clear();
        for( int i=0; i<N; i++ ) {
            int Wi, Vi, Fi;
            scanf("%d %d %d", &Wi, &Vi, &ct[i]);
            v.push_back( make_pair( Wi, Vi ) );
        }
        printf("%d\n", solve( v.size()-1, W ) );
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
