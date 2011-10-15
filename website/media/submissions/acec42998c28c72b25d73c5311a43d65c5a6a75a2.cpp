/*
 * 2
 * Sep 25, 2011,
 * Another buggy code by Khaled Samy;)
 */
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define SZ(v)					(int)v.size()
#define CLR(v, d)               memset(v, d, sizeof(v))
#define loop(i,n) 		        for(int i=0;i<(int)n;i++)
#define loop2(i,n,m)            for(int i=n;i<(int)(m);i++)

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef stringstream SS;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int OO = (int) 2e9;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2;
}

int DI[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int DJ[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
vector<int> v;
int main() {
	int t;
	int n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		v.clear();
		v.resize(n);
		loop(i,n)
			scanf("%d", &v[i]);
		// t  = 1 Srivatsan // odd even
		// t  = 2 Prashant // even odd
		int turn = 1;
		while (SZ(v) > 1) {
			pii o, e;
			o = MP(-1, -1);
			e = MP(-1, -1);
			loop(i,SZ(v)) {
				if (v[i] % 2 == 0) {
					if (e.first != -1)
						e.second = i;
					else
						e.first = i;
				} else {
					if (o.first != -1)
						o.second = i;
					else
						o.first = i;
				}
			}
			if (o.first != -1 && o.second != -1) {
				int cur = v[o.first] + v[o.second] - turn;
				v.erase(v.begin() + o.first);
				v.erase(v.begin() + o.second - 1);
				v.PB(cur);
			} else if (e.first != -1 && e.second != -1) {
				int cur = v[e.first] + v[e.second] - turn;
				v.erase(v.begin() + e.first);
				v.erase(v.begin() + e.second - 1);
				v.PB(cur);
			} else {
				int cur = v[0] + v[1] - turn;
				v.clear();
				v.PB(cur);
			}
			turn++;
		}
		if (v[0] % 2 == 0)
			cout << "LOSE\n";
		else
			cout << "WIN\n";
	}
	return 0;
}
