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

#define BUG(x) if (DEBUG) cerr << __LINE__ << ": " << #x << " = " << x << endl
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

// Faster Input Output using Pointers
const int maxBufSize = (1 << 20);
const int maxStrSize = (1 << 20);

struct Input
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	void grabBuffer() {
		bufSize = (maxBufSize); bufPos = 0;
		bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
		buffer[bufEnd] = '\0';
	}
	bool bufEof() {return bufPos == bufEnd;}
	int getChar() {return buffer[bufPos++];}
	void skipWS() {
		while ((buffer[bufPos] == '\n' ||
			buffer[bufPos] == ' ' || buffer[bufPos] == '\t')) 
			bufPos++;
	}
	int rUint() {
		int n = 0, x; skipWS();
		for (int x = getChar(); x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
		return n;
	}
	int rInt() {
		int sign = 0, n = 0, x; skipWS();
		if (buffer[bufPos] == '-')
			sign = 1, getChar();
		for (x = getChar(); x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
		return sign == 0? n: -n;
	}
	LL rLL() {
		int sign = 0, x; LL n = 0; skipWS();
		if (buffer[bufPos] == '-')
			sign = 1, getChar();
		for (x = getChar(); x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
		return n;
	}
	inline bool isWhiteSpace(char x) {
		return x == ' ' || x == '\n' || x == '\t';
	}
	string rStr() {
		char result[maxStrSize]; skipWS();
		int idx = 0, x;
		for (x = getChar(); !isWhiteSpace(x); x = getChar())
			result[idx++] = x;
		result[idx] = '\0';
		return result;
	}
	char rChar() {skipWS(); return getChar();}
};

struct Output
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	Output() {bufPos = bufEnd = 0; bufSize = maxBufSize;}
	void print(int x) {
		if (x < 0) {
			print('-'); print(-x); return;
		}
		char temp[1 << 4]; int idx = 0;
		do {
			temp[idx++] = '0' + (x % 10);
			x /= 10;
		} while (x != 0);
		temp[idx] = '\0';
		reverse(temp, temp + idx);
		print(temp);
	}
	void print(LL x) {
		if (x < 0) {
			print('-'); print(-x); return;
		}
		char temp[1 << 5]; int idx = 0;
		do {
			temp[idx++] = '0' + (x % 10);
			x /= 10;
		} while (x != 0);
		temp[idx] = '\0';
		reverse(temp, temp + idx);
		print(temp);
	}
	inline void print(char ch) {buffer[bufEnd++] = ch;}
	inline void print(const char* s) {while (*s) buffer[bufEnd++] = *s++;}
	inline void print(const string& s) {print(s.c_str());}
	inline void flushBuffer() {buffer[bufEnd] = '\0'; printf("%s", buffer); bufEnd = 0;}
	template <class A, class B> 
	void print(const A& a, const B& b) {print(a); print(b);}
	template <class A, class B, class C> 
	void print(const A& a, const B& b, const C& c) {print(a); print(b); print(c);}
};

Input input; Output output;


struct SegmentTree
{
	vector <LL> v, m; int N;
	vector <LL> tquery;
	void initialize(vector <LL>& v) {
		this -> v = v; N = size(v); N = log2(N) + 2; N = two(N);
		m.resize(N, -1); recurse(0, size(v) - 1, 1);
		for (int i = 0; i < size(v); ++i)
			tquery.push_back(query(0, i));
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
	vector < pair <int, LL> > wvR;
	vector < pair <int, LL> > wvL;
	SegmentTree tree;
	void recurse(LL W, int idx, vector < pair <int, LL> >& wv, vector <int>& f, vector < pair <int, LL> >& result, vector <int>& content, LL w, LL v) {
		if (w > W) return;
		if (idx == size(wv)) {
			if (w <= 1e8)
				result.push_back(make_pair(w, v));
		}
		else {
			for (content[idx] = 0; content[idx] <= f[idx]; ++content[idx])
				recurse(W, idx + 1, wv, f, result, content, w + wv[idx].first * content[idx], v + wv[idx].second * content[idx]);
		}
	}
	void build(LL W, vector < pair <int, LL> >& wv, vector <int>& f, vector < pair <int, LL> >& result) {
		vector <int> content(size(f), 0);
		recurse(W, 0, wv, f, result, content, 0, 0);
	}

	int binarySearch(vector < pair <int, LL> >& wv, int low, int high, LL value) {
		if (wv[high].first <= value) return high;
		while (low < high) {
			int mid = (low + high) >> 1;
			if (wv[mid].first <= value && (wv[mid + 1].first > value)) return mid;
			else if (wv[mid].first <= value) low = mid + 1;
			else high = mid;
		}
		return low;
	}
	LL solve(LL W, vector < pair <int, LL> >& left_wv, vector < pair <int, LL> >& right_wv,
				vector <int>& left_f, vector <int>& right_f) {
			///////////////////////////////////////////////////
			wvL.reserve(1 << 20); wvR.reserve(1 << 20);
			build(W, right_wv, right_f, wvR);
			build(W, left_wv, left_f, wvL);
			sort(wvR.begin(), wvR.end());
			vector <LL> vTree;
			for (int i = 0; i < size(wvR); ++i)
				vTree.push_back(wvR[i].second);
			tree.initialize(vTree);
			LL result = 0;
			for (int i = 0; i < size(wvL); ++i) {
				LL w_i = wvL[i].first, v_i = wvL[i].second;
				if (W - w_i >= 0) {
					int targetW_i = W - w_i;
					int idx = binarySearch(wvR, 0, size(wvR) - 1, targetW_i);
					if (idx == -1) continue;
					LL maximum = tree.tquery[idx];
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
		input.clear();
		int leftEnd = (N / 2) - 1, rightStart = (N / 2);
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
	const bool contest = true;
	if (contest == true) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	input.grabBuffer();
	int nTest = input.rInt();
	for (int test = 1; test <= nTest; ++test) {
		int N = input.rInt(), W = input.rInt();
		vector < pair <int, pair <int, int> > > v;
		for (int i = 0; i < N; ++i) {
			int w_i = input.rInt(), v_i = input.rInt(), f_i = input.rInt();
			v.push_back(make_pair(w_i, make_pair(v_i, f_i)));
		}
		Solver solver;
		LL result = solver.solve(N, W, v);
		output.print(result, '\n');
		//printf("%lld\n", result);
	}
	output.flushBuffer();
	return 0;
}

// Powered by PhoenixAI
