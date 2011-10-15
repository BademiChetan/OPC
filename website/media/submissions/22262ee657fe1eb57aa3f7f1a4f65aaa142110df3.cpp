#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <complex>
#include <sstream>
#include <iomanip>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

const double PI = acos(-1.0);

int phi(int k) {
    int res = 1;
    for(int i = 2; i*i <= k; i++) if (k % i == 0) {
        int p = 1;
        while (k % i == 0) {
            p *= i;
            k /= i;
        }
        res *= (p - p / i);
    }
    if (k > 1) res *= (k-1);
    return res;
}

int power(int x, int n, int BASE) {
    if (n == 0) return 1;
    if (n == 1) return x;
    ll mid = power(x, n >> 1, BASE);
    mid = (mid * mid) % BASE;
    if (n & 1) return (mid * x) % BASE;
    else return mid;
}

int main() {
//    freopen("test.in", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int test, n, k;
    scanf("%d", &test);
    while (test--) {
        scanf("%d %d", &n, &k);
        if (k == 1) {
            puts("0");
            continue;
        }
        int p = phi(k);
//        cout << "p = " << p << endl;
        int b = (int) power(2, n, p);
//        cout << "b = " << b << endl;
        printf("%d\n", (int) (power(2, b, k)));
    }
    return 0;
}
