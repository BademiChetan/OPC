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


int main() {

//	freopen("PT07Z longest path in a tree.in", "rt", stdin);
//	freopen("PT07Z longest path in a tree.out", "wt", stdout);
//	memset(vis, 0, sizeof vis);
	int n,num,t,pairs;
	cin >>t;
	for (int tt = 0; tt < t; ++tt) {
		cin >> n;
		bool player =0;
		int o = 0, e= 0;

		for (int i = 0; i < n; ++i) {
			cin >> num;
			if(num%2==0)
				e++;
			else
				o++;
		}
		while(e >1 || o >1)
		{
			pairs = e/2 + o/2;
			player = (player + pairs)%2;
			e = e%2;
			o = o%2;
			o += ceil(pairs/2.0);
			e += pairs/2;
		}
		if((e == 1 && o ==1 && player )||(e == 0 && o == 1))
			cout << "WIN\n";
		else
			cout<<"LOSE\n";

	}

	
	return 0;
}
