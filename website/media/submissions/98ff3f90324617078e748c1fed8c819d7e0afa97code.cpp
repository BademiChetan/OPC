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

vector<pii> obj; // cost, value
vector<pii> par[2]; // cost, value
int id, lim;

void go(int pos, int totval = 0, int totcost = 0) {
	if (pos == lim) {
		par[id].pb(pii(totcost, totval));
		return;
	}
	go(pos+1, totval, totcost);
	go(pos+1, totval+obj[pos].second, totcost+obj[pos].first);
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		FOR(i, 0, 2) par[i].clear();
		obj.clear();
		int n, total;
		cin >> n >> total;
		FOR(i, 0, n) {
			int c, v, f;
			cin >> c >> v >> f;
			int p2 = 1;
			while (p2*2 <= f) p2 *= 2;
			p2 /= 2;
			while (p2) {
				if (p2 <= f) {
					f -= p2;
					obj.pb(pii(c*p2, v*p2));
				}
				p2 /= 2;
			}
			if (f) obj.pb(pii(c*f, v*f));
		}
		id = 0; lim = Size(obj)/2; go(0);
		id = 1; lim = Size(obj); go(Size(obj)/2);
		FOR(i, 0, 2) sort(all(par[i]));
		FOR(i, 1, Size(par[1])) par[1][i].second = max(par[1][i].second, par[1][i-1].second);
		int p0 = 0, p1 = Size(par[1])-1;
		int maxres = 0;
		while (p0 < Size(par[0])) {
			while (p1 > 0 && par[1][p1].first > total-par[0][p0].first) p1--;
			if (par[1][p1].first <= total-par[0][p0].first) maxres = max(maxres, par[0][p0].second+par[1][p1].second);
			p0++;
		}
		cout << maxres << endl;
	}
	return 0;
}

