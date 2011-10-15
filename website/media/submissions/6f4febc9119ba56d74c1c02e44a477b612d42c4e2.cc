#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
 
#define r(i, n) rb(i, 0, n)
#define rb(i, b, n) rbc(i, b, n, <)
#define re(i, n) rbe(i, 0, n)
#define rbe(i, b, n) rbc(i, b, n, <=)
#define rbc(i, b, n, c) for(int i = (b); i c ((int)(n)); i++)
 
#define ri r(i, n)
#define rj r(j, n)
#define rk r(k, n)
#define rim r(i, m)
#define rjm r(j, m)
#define rkm r(k, m)

#define p(x) cout << x << " "
#define pl cout << endl
#define pn(x) cout << x << endl
#define pv(v) ri { p(v[i]); } pl;
#define pm(m) ri { rjm { p(m[i][j]); } pl; } pl;
#define pp(x) " "#x" " << x
#define ppn(x) pn(pp(x))
#define ppp(x) p(pp(x))

#define in(x) cin >> x
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
 
int main() {
  bool dp[110][110] = {{0}};
  dp[1][0] = 0;
  dp[1][1] = 1;
  rb(i, 2, 110) {
    r(j, i + 1) {
      bool &cur = dp[i][j];
      cur = 0;
      if (j >= 2) {
        cur = cur || dp[i - 1][j - 2 + !!!(i % 2)];
      }
      if (i - j >= 2) {
        cur = cur || dp[i - 1][j + !!!(i % 2)];
      }
      if (j >= 1 && i - j >= 1) {
        cur = cur || dp[i - 1][j - 1 + !!(i % 2)];
      }
      cur = !cur;
    }
  }
  /*
  r(i, 10) {
    r(j, i + 1) {
      cout << dp[i][j] << " ";
    }
    pl;
  }
  pl;//*/
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int cnt = 0;
    ri {
      int v;
      cin >> v;
      cnt += !!!(v % 2);
    }
    cout << (dp[n][cnt] ? "LOSE" : "WIN") << endl;
  }
} 

