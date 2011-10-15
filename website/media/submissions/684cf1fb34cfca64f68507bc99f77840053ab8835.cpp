#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <complex>
#include <sstream>
#include <iomanip>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

const double PI = acos(-1.0);

pair<int,int> a[111];
int s, W;

int n[2];
pair<int,int> all[2][1100111];

void add(int w, int v, int f) {
    s++;
    a[s] = MP(w*f, v*f);
}

void gen(int t, int l, int r, int cost, int val) {
    if (l > r) {
        if (cost > W) return ;
        all[t][++n[t]] = MP(cost, val);
        return ;
    }
    
    gen(t, l+1, r, cost, val);
    gen(t, l+1, r, cost + a[l].F, val + a[l].S);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int test; scanf("%d", &test);
    while (test--) {
        n[0] = n[1] = 0;
        int N;
        scanf("%d %d", &N, &W);
        FOR(i,1,N) {
            int w, v, f;
            scanf("%d %d %d", &w, &v, &f);
            for(int x = 1; x <= 8; x *= 2) if (f >= x) {
                f -= x;
                add(w, v, x);
            }
            if (f) {
                add(w, v, f);
            }
        }
        
        gen(0, 1, s/2, 0, 0);
        gen(1, s/2 + 1, s, 0, 0);
                
        sort(all[0] + 1, all[0] + n[0] + 1);
        /*
        FOR(i,1,s/2) cout << a[i].F << ' ' << a[i].S << endl;
        FOR(i,1,n[0]) cout << "(" << all[0][i].F << ' ' << all[0][i].S << ") "; puts("");

        FOR(i,s/2+1,s) cout << a[i].F << ' ' << a[i].S << endl;
        FOR(i,1,n[1]) cout << "(" << all[1][i].F << ' ' << all[1][i].S << ") "; puts("");
        */
        
        int sc = 1;
        FOR(i,2,n[0]) {
            all[0][i].S = max(all[0][i].S, all[0][i-1].S);
        }
        
        FOR(i,2,n[0]) {
            if (all[0][i].F > all[0][i-1].F) {
                sc++;
                all[0][sc] = all[0][i];
            }
            else all[0][sc].S = max(all[0][sc].S, all[0][i].S);
        }
        
//        FOR(i,1,sc) cout << all[0][i].F << ' ' << all[0][i].S << endl;
        
        int res = 0, left, add;
        FOR(i,1,n[1]) {
            left = W - all[1][i].F;
            if (left >= all[0][sc].F) add = sc + 1;
            else add = upper_bound(all[0] + 1, all[0] + sc, MP(left+1, 1)) - all[0];
            add--;
//            cout << all[1][i].F << ' ' << all[0][add].F << ' ' << all[0][add].S << endl;
            res = max(res, all[1][i].S + all[0][add].S);
        }
        
        printf("%d\n", res);
    }
    return 0;
}
