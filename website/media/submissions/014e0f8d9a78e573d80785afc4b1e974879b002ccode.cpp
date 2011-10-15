/*
ID: hamed_51
PROG: ?
LANG: C++
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <assert.h>
#include <ctime>
#include <bitset>
#include <numeric>
#include <complex>
using namespace std;

#if (_win32 || __win32__)
#define LLD "%i64d"
#else
#define LLD "%lld"
#endif

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
#define ll long long
#define pb push_back
#define error(x) cout << #x << " = " << x << endl;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define point complex<double>
//#define X real()
//#define Y imag()
#define X first
#define Y second
#define EPS 1e-8
#define endl "\n"

inline void read(register int *n) {
	register char c; *n = 0;
	do { c = getchar(); } while (c < '0' || c > '9');
	do { *n = c-'0'+*n*10; c = getchar(); } while (c >= '0' && c <= '9');
}

ll p2mod(int y, int MOD) {
	if (y == 0) return 1;
	if (y%2) {
		return (p2mod(y-1, MOD)*2)%MOD;
	} else {
		ll r = p2mod(y/2, MOD);
		return (r*r)%MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int p2 = 2, cnt = 0;
		int n, K;
		cin >> n >> K;
		if (K == 1) {
			cout << 0 << endl;
			continue;
		}
		do {
			p2 += p2;
			cnt++;
			if (p2 >= K) p2 -= K;
		} while (p2 != 2);
		cout << p2mod(p2mod(n, cnt), K) << endl;
	}
	return 0;
}

