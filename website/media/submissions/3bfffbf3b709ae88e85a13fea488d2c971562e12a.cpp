#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

/*#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;*/

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;

int base[4][4] = { { 0, 1, 2, 3 }, { 1, 0, 3, 2 }, { 2, 3, 0, 1 },
		{ 3, 2, 1, 0 } };

int main() {
#ifndef ONLINE_JUDGE
	//freopen("a.txt", "rt", stdin);
#endif
	int N, I, J;
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d", &I, &J);
		int size = 1;
		while (max(I, J) + 1 > size)
			size <<= 2;
		while (I > 3) {
			int qsize = size / 4;
			int ii = I / qsize;
			int jj = J / qsize;
			I -= ii * qsize;
			J = base[ii][jj] * qsize + J % qsize;
			size = qsize;
		}
		int jj = J / 4;
		jj *= 4;
		int same = J - jj;
		printf("%d\n", base[I][same] + jj);
	}
	return 0;
}
