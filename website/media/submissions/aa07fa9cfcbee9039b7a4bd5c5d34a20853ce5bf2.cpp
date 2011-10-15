#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define SET(x,a) memset(x,a,sizeof(x))
#define all(a) (a.begin(),a.end())
#define rall(a) (a.rbegin(),a.rend())
#define INF (int)1e9
#define EPS (double)1e-9

typedef unsigned long long ULL;
typedef long long LL;
typedef set <int> si;
typedef pair< int,int > ii;
typedef pair< int, ii > pi;
typedef vector< ii > vii;
typedef vector < vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int main() {
	int T = GI;
	while(T--) {
		int N = GI, sum = 0;
		REP(i,N) {
			int a = GI;
			sum += a - (i+1);
		}
		if (sum%2 == 0) printf("LOSE\n");	
		else printf("WIN\n");
	}	
	return 0;
}
