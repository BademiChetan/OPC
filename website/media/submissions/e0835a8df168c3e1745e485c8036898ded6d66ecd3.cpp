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
const int BASE = 1000000007;

bool isPrime(int K) {
    for(int i = 2; i < min(10,K); i++) if (K % i == 0) return false;
    return true;
}

ll power(int x, int k, ll BASE) {
    if (k == 1) return x;
    if (k == 0) return 1;
    ll mid = power(x, k/2, BASE);
    mid = (mid * mid) % BASE;
    if (k & 1) return (mid * x) % BASE;
    else return mid;
}

int c[1011][1011];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    c[0][0] = 1;
    FOR(i,1,1000) {
        c[i][0] = 1;
        FOR(j,1,1000) c[i][j] = (c[i-1][j-1] + c[i-1][j]) % BASE;
    }
    
    int test; scanf("%d", &test);
	while (test--) {
        int N, K;
        cin >> N >> K;
        
        if (K == 2) {
            printf("%d\n", (int) ((2 * power(4, N/K-1, BASE)) % BASE));
            continue;
        }
        
            ll res = 0;
            
            /*
            FOR(k,0,N) {
                int x = 0;
                if (k % K == 0) {
                    x = c[N/K][k/K];
                }
                
                int now = ((c[N][k] - x) * power(K, BASE-2, BASE)) % BASE;
                
                res = (res + now) % BASE;
            }
            */
            
            res = 0;
            res = (power(2, N, BASE) * power(K, BASE - 2, BASE)) % BASE;
            
            ll sx = power(2, N/K, BASE);
            
            ll tmp = (sx * power(K, BASE - 2, BASE)) % BASE;
            
            res = (res - tmp + sx + BASE) % BASE;
            
            printf("%d\n", (int)res);
    }
    
    return 0;
}
