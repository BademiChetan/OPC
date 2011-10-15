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
#define ulong long long

inline void read(register int *n) {
	register char c; *n = 0;
	do { c = getchar(); } while (c < '0' || c > '9');
	do { *n = c-'0'+*n*10; c = getchar(); } while (c >= '0' && c <= '9');
}

typedef struct { ulong p, e; } prime_factor; /* prime, exponent */
 
int get_prime_factors(ulong n, prime_factor *lst)
{
	ulong i, e, p;
	ll len = 0;
 
	for (i = 2; i*i <= n; i++) if (n%i == 0) {
		p = i;
		for (e = 0; !(n % p); n /= p, e++);
		if (e) {
			lst[len].p = p;
			lst[len++].e = e;
		}
	}
 
	return n == 1 ? len : (lst[len].p = n, lst[len].e = 1, ++len);
}

int ulong_cmp(const void *a, const void *b)
{
	return *(ulong*)a < *(ulong*)b ? -1 : *(ulong*)a > *(ulong*)b;
}
 
int get_factors(ulong n, ulong *lst)
{
	ll n_f, len, len2, i, j, k, p;
	prime_factor f[100];
 
	n_f = get_prime_factors(n, f);
 
	len2 = len = lst[0] = 1;
	/* L = (1); L = (L, L * p**(1 .. e)) forall((p, e)) */
	for (i = 0; i < n_f; i++, len2 = len)
		for (j = 0, p = f[i].p; j < f[i].e; j++, p *= f[i].p)
			for (k = 0; k < len2; k++)
				lst[len++] = lst[k] * p;
 
	qsort(lst, len, sizeof(ulong), ulong_cmp);
	return len;
}


ulong mpow(ulong a, ulong p, ulong m)
{
	ulong r = 1;
	while (p) {
		if ((1 & p)) r = r * a % m;
		a = a * a % m;
		p >>= 1;
	}
	return r;
}
 
ulong ipow(ulong a, ulong p) {
	ulong r = 1;
	while (p) {
		if ((1 & p)) r = r * a;
		a *= a;
		p >>= 1;
	}
	return r;
}
 
ulong gcd(ulong m, ulong n)
{
	ulong t;
	while (m) { t = m; m = n % m; n = t; }
	return n;
}
 
ulong lcm(ulong m, ulong n)
{
	ulong g = gcd(m, n);
	return m / g * n;
}
 
ulong multi_order_p(ulong a, ulong p, ulong e)
{
	ulong fac[10000];
	ulong m = ipow(p, e);
	ulong t = m / p * (p - 1);
	ulong i, len = get_factors(t, fac);
	for (i = 0; i < len; i++)
		if (mpow(a, fac[i], m) == 1)
			return fac[i];
	return 0;
}
 
ulong multi_order(ulong a, ulong m)
{
	prime_factor pf[100];
	ulong i, len = get_prime_factors(m, pf);
	ulong res = 1;
	for (i = 0; i < len; i++)
		res = lcm(res, multi_order_p(a, pf[i].p, pf[i].e));
	return res;
}

ll pmod(ll x, ll y, ll MOD) {
	if (y == 0) return 1;
	if (y%2) {
		return (pmod(x, y-1, MOD)*x)%MOD;
	} else {
		ll r = pmod(x, y/2, MOD);
		return (r*r)%MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll n, K;
		cin >> n >> K;
		if (K != 1)
			cout << pmod(2, pmod(2, n, multi_order(2, K)), K) << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}

