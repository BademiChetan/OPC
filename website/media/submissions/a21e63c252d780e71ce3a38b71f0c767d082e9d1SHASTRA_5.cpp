#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

vector< pair< int,int > > v;
map< pair<int,int>, int > memo;

int solve( int idx, int W ) {
    if ( idx < 0 ) return 0;
    if ( memo.count( make_pair( idx, W ) ) > 0 ) return memo[ make_pair( idx, W ) ];
    if ( v[idx].first > W ) return memo[ make_pair( idx, W ) ] = solve( idx-1, W );
    return memo[ make_pair( idx, W ) ] = max( solve( idx-1, W ), solve( idx-1, W-v[idx].first ) + v[idx].second );
}

int main() {
    int ntc;
    scanf("%d", &ntc);
    while( ntc-- ) {
        int N, W;
        scanf("%d %d", &N, &W);
        v.clear();
        memo.clear();
        for( int i=0; i<N; i++ ) {
            int Wi, Vi, Fi;
            scanf("%d %d %d", &Wi, &Vi, &Fi);
            for( int k=1; k <= Fi; k++ ) {
                v.push_back( make_pair( Wi, Vi ) );
            }
        }
        printf("%d\n", solve( v.size()-1, W ) );
    }
    return 0;
}
