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

const int iter = 30;
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
	vector <int> primes;
	Solver() {
		vector <bool> sieve(100000, true);
		sieve[0] = sieve[1] = false;
		for (int i = 2; i * i < size(sieve); ++i)
			if (sieve[i] == true)
				for (int j = i * i; j < size(sieve); j += i)
					sieve[j] = false;
		for (int i = 2; i < size(sieve); ++i)
			if (sieve[i] == true)
				primes.push_back(i);
	}
	void solve(int N, int K) {
		int originalK = K;
		int phiK = K;
		vector <int> factors;
		for (int i = 0; i < size(primes) && primes[i] * primes[i] <= K; ++i) {
			if (K % primes[i] == 0) {
				factors.push_back(primes[i]);
				while (K % primes[i] == 0)
					K /= primes[i];
			}
		}
		if (K > 1) factors.push_back(K);
		K = originalK;
		for (int i = 0; i < size(factors); ++i)
			phiK = (phiK * (long long) (factors[i] - 1)) / factors[i];
		Exponentiation expo;
		int newPower = expo.power(2, N, phiK);
		int result = expo.power(2, newPower, K);
		//cout << result << endl;
		output.print(result, '\n');
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
		//int N = rInt(), K = rInt();
		int N = input.rInt(), K = input.rInt();
		solver.solve(N, K);
	}
	return 0;
}

// Powered by PhoenixAI
