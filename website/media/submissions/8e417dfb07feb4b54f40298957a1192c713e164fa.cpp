#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define eps 1e-8
#define oo 1e9


using namespace std;

int T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an;

int main(){
        scanf("%d", &T);
        while (T--){
                scanf("%d", &m);
                s = 0;
                for (int i=0; i<m; i++){
                        scanf("%d", &q);
                        s = (s+q)%2;
                }
                s = (s+(m-1))%2;
                if (s&1)
                        puts("WIN");
                else puts("LOSE");
        }

        return 0;
}