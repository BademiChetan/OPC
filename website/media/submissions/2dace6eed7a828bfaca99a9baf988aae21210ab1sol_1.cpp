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

struct SegmentTree
{
	vector <LL> v, m; int N;
	void initialize(vector <LL>& v) {
		this -> v = v; N = size(v); N = log2(N) + 3; N = two(N);
		m.resize(N, -1); recurse(0, size(v) - 1, 1);
	}
	void recurse(int b, int e, int node) {
		if (b == e) m[node] = v[b];
		else {
			int mid = (b + e) >> 1;
			recurse(b, mid, (node << 1));
			recurse(mid + 1, e, 1 + (node << 1));
			m[node] = max(m[(node << 1)], m[1 + (node << 1)]);
		}
	}
	LL query(int low, int high) {
		if (low >= 0 && high < size(v))
			return query(0, size(v) - 1, 1, low, high);
		else
			return -1;
	}
	LL query(int b, int e, int node, int low, int high) {
		if (b > high || e < low) return -1;
		else if (b >= low && e <= high) return m[node];
		else {
			int mid = (b + e) >> 1;
			int first = query(b, mid, (node << 1), low, high);
			int second = query(mid + 1, e, 1 + (node << 1), low, high);
			return max(first, second);
		}
	}
};

struct Solver
{
	void recurse(int idx, vector < pair <int, LL> >& wv, vector <int>& f, vector < pair <int, LL> >& result, vector <int>& content) {
		if (idx == size(wv)) {
			LL w = 0, v = 0;
			for (int i = 0; i < idx; ++i)
				w += wv[i].first * content[i], v += wv[i].second * content[i];
			if (w <= 1e8)
				result.push_back(make_pair(w, v));
		}
		else {
			for (content[idx] = 0; content[idx] <= f[idx]; ++content[idx])
				recurse(idx + 1, wv, f, result, content);
		}
	}
	void build(vector < pair <int, LL> >& wv, vector <int>& f, vector < pair <int, LL> >& result) {
		vector <int> content(size(f), 0);
		recurse(0, wv, f, result, content);
	}
	int binarySearch(vector < pair <int, LL> >& wv, int low, int high, LL value) {
		if (wv[high].first <= value) return high;
		while (low <= high) {
			int mid = (low + high) >> 1;
			if (wv[mid].first <= value && (mid + 1 < size(wv) && wv[mid + 1].second > value)) return mid;
			else if (wv[mid].first <= value) low = mid + 1;
			else high = mid;
		}
		return -1;
	}
	LL solve(LL W, vector < pair <int, LL> >& left_wv, vector < pair <int, LL> >& right_wv,
				vector <int>& left_f, vector <int>& right_f) {
			///////////////////////////////////////////////////
			vector < pair <int, LL> > wvL, wvR;
			build(left_wv, left_f, wvL);
			build(right_wv, right_f, wvR);
			sort(wvR.begin(), wvR.end());
			vector <LL> vTree;
			for (int i = 0; i < size(wvR); ++i)
				vTree.push_back(wvR[i].second);
			SegmentTree tree;
			tree.initialize(vTree);
			LL result = 0;
			for (int i = 0; i < size(wvL); ++i) {
				int w_i = wvL[i].first, v_i = wvL[i].second;
				if (W - w_i >= 0) {
					int targetW_i = W - w_i;
					int idx = binarySearch(wvR, 0, size(wvR) - 1, targetW_i);
					LL maximum = tree.query(0, idx);
					if (v_i + maximum > result)
						result = v_i + maximum;
				}
			}
			return result;
	}
	LL solve(int N, int W, vector < pair <int, pair <int, int> > >& input) {
		vector < pair <int, LL> > wv;
		vector <int> f;
		for (int i = 0; i < size(input); ++i)
			wv.push_back(make_pair(input[i].first, input[i].second.first));
		for (int i = 0; i < size(input); ++i)
			f.push_back(input[i].second.second);
		int leftEnd = (N / 2), rightStart = (N / 2) + 1;
		vector < pair <int, LL> > left_wv, right_wv;
		vector <int> left_f, right_f;
		for (int i = 0; i <= leftEnd; ++i)
			left_wv.push_back(wv[i]), left_f.push_back(f[i]);
		for (int i = rightStart; i < size(wv); ++i)
			right_wv.push_back(wv[i]), right_f.push_back(f[i]);
		return solve(W, left_wv, right_wv, left_f, right_f);
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
	for (int test = 1; test <= nTest; ++test) {
		int N = rInt(), W = rInt();
		vector < pair <int, pair <int, int> > > v;
		for (int i = 0; i < N; ++i) {
			int w_i = rInt(), v_i = rInt(), f_i = rInt();
			v.push_back(make_pair(w_i, make_pair(v_i, f_i)));
		}
		Solver solver;
		LL result = solver.solve(N, W, v);
		printf("%lld\n", result);
	}
	return 0;
}

// Powered by PhoenixAI
