/*
 * 1
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

//int g[101][101];
////int n;
//int visr[101][101], visc[101][101];
//void solve() {
//	int x = 0;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++) {
//			x = 0;
//			while (1) {
//				if (!visr[i][x] && !visc[j][x]) {
//					visr[i][x] = 1, visc[j][x] = 1;
//					g[i][j] = x;
//					break;
//				}
//				x++;
//			}
//		}
//}
long long FastPower(long long a, long long n, long long mod) {
	if (n == 0)
		return 1;
	long long x = FastPower(a, n / 2, mod);
	if (n % 2 == 0)
		return (x * x) % mod;
	return (((x * x) % mod) * a) % mod;
}

int main() {
//	freopen("in.txt", "rt", stdin);
	//	while (1) {
	//		cin >> n;
	//		if (n == -1)
	//			break;
	//		solve();
	//		//	for (int i = 0; i < n; i++) {
	//		//		for (int j = 0; j < n; j++) {
	//		//			if (i + j == g[i][j])
	//		//				cout << "1 ";
	//		//			else if (abs(i - j) == g[i][j])
	//		//				cout << "0 ";
	//		//			else
	//		//				cout << "2 ";
	//		//		}
	//		//		cout << endl;
	//		//	}
	//		//	cout << endl;
	//		CLR(visc,0);
	//		CLR(visr,0);
	//
	//		for (int i = 0; i < n; i++) {
	//			for (int j = 0; j < n; j++)
	//				cout << g[i][j] << " ";
	//			cout << endl;
	//		}
	//		cout << endl;
	//	}
//	int t;
//	ll n, k;
//	scanf("%d", &t);
//	while (t--) {
//		cin >> n >> k;
//		ll x = FastPower(2, n, k);
//		ll y = FastPower(2, x, k);
//		cout << y << endl;
//	}
	int tst;
	scanf("%d",&tst);
	int r,c;
	while(tst--){
		scanf("%d %d",&r,&c);
		int n = 1000000;
		int ansr = n-r;
		int ansc = (ansr+c)%n;
		printf("%d\n",ansc);
	}
	return 0;
}
