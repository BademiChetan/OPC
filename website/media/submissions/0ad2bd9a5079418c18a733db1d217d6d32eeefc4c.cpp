/*
 ID: ahmed.f2
 LANG: C++
 TASK: PT07Z longest path in a tree
 */

#include <iostream>
#include <cstring>
#include <string.h>
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

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(v) (int)v.size()

#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;

const int oo = (int) 1e9;
const double PI = 3.141592653589793;
const double eps = 1e-11;
#define mx 1000
int arr[8][8] = {{0,    1,    2,    3,    4,    5,    6,    7},
{1,    0,    3,    2,    5,    4,    7,    6},

{2,    3 ,   0 ,   1 ,   6 ,   7 ,   4 ,   5},

{3,    2 ,   1 ,   0 ,   7  ,  6 ,   5,    4},

{4,    5 ,   6 ,   7 ,   0 ,   1  ,  2   , 3},
{5,    4 ,   7  ,  6  ,  1 ,   0,    3  ,  2 },

{6,    7 ,   4  ,  5  ,  2  ,  3,    0 ,   1},
{7,    6  ,  5 ,   4 ,   3  ,  2 ,   1  ,  0}};

int main() {

//	freopen("PT07Z longest path in a tree.in", "rt", stdin);
//	freopen("PT07Z longest path in a tree.out", "wt", stdout);
//	memset(vis, 0, sizeof vis);
	int n=1, x, y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
//for (int x = 0; x < 20; ++x) {
//	for (int y = 0; y < 20; ++y) {
cout<< arr[(x/8)%8][(y/8)%8]*8 + arr[x%8][y%8] <<endl;
//	}
//	cout <<endl;
}

//}
	return 0;
}
