// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int k;

const int M = 100;
const int N = 1000;

int cache[M][N];

int fun(int b, int n) {
	if(b<M && n<N && cache[b][n] != -1)
		return cache[b][n];

	int ans;

	if(n == 0)  {
		ans = b %k;
	} else if(n&1) {
		int x =  fun(b, n-1);
		ans = ((LL) x * x) % k;
	} else {
		int y = fun(b, n>>1);
		ans = fun(y, n>>1);
	}

	if(b<M && n<N) cache[b][n] = ans;
	return ans;
}

int main() {
	int t;
	scanf("%d",&t);
	SET(cache, -1);
	while(t--) {
		int n;
		scanf("%d %d" ,&n, &k);
		printf("%d\n",fun(2,n));
	}
	return 0;
}

