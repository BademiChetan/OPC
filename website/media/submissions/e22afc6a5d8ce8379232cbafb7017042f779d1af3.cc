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
  int T;
  cin >> T;
  while (T--) {
    ull n, k;
    scanf("%Ld%Ld", &n, &k);
    ull res = 2;
    map<ull, int> mp;
    vector<ull> v;
    v.push_back(2);
    mp[2] = 0;
    ri {
      res = (res * res) % k;
      //ppn(res);
      v.push_back(res);
      map<ull, int>::iterator it;
      if ((it = mp.find(res)) != mp.end()) {
        //ppn(res);
        //ppn(i);
        //ppn(it->second);
        int per = i - it->second;
        int end = 0;
        if (per != 0) {
          end = (n - it->second) % per;
        }
        //ppn(per);
        //ppn(end);
        res = v[end + it->second];
        break;
      }
      mp[res] = i + 1;
    }
    printf("%Ld\n", res);
  }
} 

