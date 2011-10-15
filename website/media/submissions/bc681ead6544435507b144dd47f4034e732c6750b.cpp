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
//	for (int i = 0; i < 2; ++i) {
//		for (int j = 0; j < 2; ++j) {
//			for (int k = 0; k < 2; ++k) {
//				for (int l = 0; l < 2; ++l) {
//					cout << 4 << endl << i <<" " << j <<" "<<k << " " << l <<endl;
//				}
//			}
//		}
//	}
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
//		cout << e <<" " << o <<endl;
		while(e >1 || o >1)
		{
//			cout << "asd"<<endl;
			pairs = e/2 + o/2;

			e = e%2;
			o = o%2;
			o += pairs/2 + (pairs%2 && !player);
			e += pairs/2 +  (pairs%2 && !player);
			player = (player + pairs)%2;
		}
		if((e == 1 && o ==1 && player )||(e == 0 && o == 1))
			cout << "WIN\n";
		else
			cout<<"LOSE\n";

	}

	
	return 0;
}
