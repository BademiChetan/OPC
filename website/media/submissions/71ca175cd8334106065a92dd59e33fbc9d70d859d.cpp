#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define mod 1000000007
using namespace std;

int T,n,p;

long long power(long long x,long long deg) {
    if (!deg) return 1;
    long long q = power(x,deg/2);
    q = (q * q) % mod;
    if (deg & 1) q = (q * x) % mod;
    return q;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &p);
        long long ret = power(2,n);
        ret = (ret + mod - 2) % mod;
        ret = (ret * power(p,mod - 2)) % mod;
        if (p == 2) ret++; else ret += 2;
        ret %= mod;
        cout << ret << endl;
    }
}
