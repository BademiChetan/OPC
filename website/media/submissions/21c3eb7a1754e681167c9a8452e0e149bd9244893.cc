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

char out[100000] = "";
 
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    ull res = 2;
    set<ull> *st = new set<ull>;
    int it = -1;
    int target = -1;
    int per = -1;
    ri {
      res = (res * res) % k;
      //ppn(res);
      if (per == -1 && (int)res == target) {
        per = i - it;
        int end = 0;
        if (per != 0) {
          end = (n - it) % per;
        }
        //ppn(per);
        //ppn(end);
        n = end + it;
        while ((int) n <= i) n += per;
        //n++;
      }
      if (target == -1 && (i % 1000 == 0) && !(*st).insert(res).second) {
        //ppn(res);
        //ppn(i);
        target = res;
        it = i;
        //ppn(target);
        //ppn(it);
      }
    }
    char temp[100];
    sprintf(temp, "%Ld\n", res);
    strcat(out, temp);
    //printf("%Ld\n", res);
  }
  printf("%s", out);
} 

