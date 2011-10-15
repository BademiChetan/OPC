#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define eps 1e-8
#define oo 1e9
#define N 1000000007

using namespace std;

long long T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, k;

long long poww(long long x, long long y){

        if (y == 0) return 1;
        if (y == 1) return x;
        long long s = poww(x, y/2)%N;
        if (y%2 == 0) return s*s%N;
        return ((((s*s)%N)*x)%N);
}

int main(){
        scanf("%lld", &T);
        while (T--){
                scanf("%lld%lld", &n, &k);
                if (k == 2)
                        printf("%lld\n", poww(2, n-1));
                else printf("%lld\n", ((poww(2, n)-2)*(poww(k, N-2))%N+2)%N);
        }
        return 0;
}
