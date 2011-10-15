#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>

using namespace std;

#define BUG(x) if (DEBUG) cout << __LINE__ << ": " << #x << " = " << x << endl
#define LET(x, a) __typeof(a) x = a
#define FOREACH(it, v) for(LET(it, (v).begin()); it != (v).end(); ++it)

typedef long long LL;

template <class T> inline int size(const T& c) {return (int) c.size();}
int rInt() {int nT = -1; scanf("%d", &nT); return nT;}
string rStr() {char nStr[1 << 20] = ""; scanf("%s", nStr); return nStr;}
LL rLL() {LL nT = -1; scanf("%lld", &nT); return nT;}
inline LL two(int x) {return (1LL << (x));}
template <class T> ostream& operator << (ostream& o, const vector <T>& v)
{o << "{"; FOREACH(it, v) o << *it << ","; return o << "}";}
template <class A, class B> ostream& operator << (ostream& o, const pair <A, B>& p)
{o << "("; o << p.first << "," << p.second << ")"; return o;}

const bool DEBUG = true;
const double EPS = 1e-8;
const int INF  = 1000000000;
const LL INFLL = 1000000000000000000LL;
const LL MODULO = 1000000007;

const int iter = 31;
struct Exponentiation
{
	LL power(LL x, LL y, LL MODULO) {
		LL result = 1;
		for (int i = iter; i >= 0; --i) {
			result = (result * result) % MODULO;
			if (two(i) & y)
				result = (result * x) % MODULO;
		}
		return result;
	}
};


struct Solver
{
	int solve(int N, int K) {
		Exponentiation expo;
		LL result = expo.power(2, N, MODULO);
		if (K != 2) result = ((expo.power(2, N / K, MODULO) * ((long long)K - 1)) + result) % MODULO;
		result = (result * expo.power(K, MODULO - 2, MODULO)) % MODULO;
		return result;
	}
};

int main()
{
	const bool contest = false;
	if (contest == true) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int nTest = rInt();
	Solver solver;
	for (int test = 1; test <= nTest; ++test) {
		int N = rInt(), K = rInt();
		int result = solver.solve(N, K);
		printf("%d\n", result);
	}
	return 0;
}

// Powered by PhoenixAI
