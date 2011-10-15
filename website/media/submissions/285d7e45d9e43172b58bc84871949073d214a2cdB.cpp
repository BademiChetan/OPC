#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>

#define oo 1000000005
#define eps 1e-11

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

using namespace std;

const double PI = 2.0 * acos (0.0);

typedef long long LL;
typedef pair <int, int> PII;

inline int getInt () { int x; scanf ("%d", &x); return x; }
inline LL getLL () { LL x; scanf ("%lld", &x); return x; };
inline int NUM (char c) { return (int)c - 48; }
inline char CHR (int n) { return (char)(n + 48); }
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

inline int BPM (int a, int b, int MOD) {
    if (a == 0)
        return 0;
    if (b == 0)
        return 1 % MOD;
    if (b % 2 == 1)
        return (int)((LL) BPM (a, b - 1, MOD) * a % MOD);
    int tmp = BPM (a, b / 2, MOD);
    return (int)((LL) tmp * tmp % MOD);
}

inline int phi (int N) {
    int ret = N;
    for (int i = 2; N > 1; i++) {
        if (i * i > N) {
            ret -= ret / N;
            break;
        }
        if ( N % i == 0 ) {
            ret -= ret / i;
            while (N % i == 0)
                N /= i;
        }
    }
    return ret;
}

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

// ptrrsn_1's template

int nTC;
int N;

int main () {
	// OPEN("B");
	
	scanf("%d", &nTC);
    
    while (nTC--) {
		scanf("%d", &N);
		int tot = 0;
		REP (i, N) {
			int x = getInt();
			tot += x % 2;
			tot %= 2;
		}
		tot %= 2;
		FOR (i, 1, N - 1) {
			tot += i;
			tot %= 2;
		}
		tot %= 2;
		if (tot == 0) puts ("LOSE");
		else puts("WIN");
	}
    
    return 0;
}
