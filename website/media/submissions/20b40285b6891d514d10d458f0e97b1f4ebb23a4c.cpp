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
using namespace std;

int T,n,k;

long long power(long long x,long long p,long long mod) {
    if (!p) return (1 % mod);
    long long q = power(x,p/2,mod);
    q = (q * q) % mod;
    if (p & 1) q = (q * x) % mod;
    return q;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        int mod = k;
        if (k == 1) {
            printf("0\n");
            continue;
        }
        int phi = 1;
        for (int i = 3; i * i <= k; i += 2) while (k % i == 0) {
            k /= i;
            phi *= (i - 1);
        }
        if (k > 1) phi *= (k - 1);
        long long deg = power(2,n,phi);
        long long ans = power(2,deg,mod);
        cout << ans << endl;
    }
}
