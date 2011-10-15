#include<stdio.h>
#define Rep(i, n) for((i) = 0; (i) < (n); ++(i))

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, i; scanf("%d", &n);
        int res = 0;
        Rep(i, n) {
            int x; scanf("%d", &x);
            res ^= (x&1);
        }
        if(res == 0) printf("WIN\n");
        else printf("LOSE\n");
    }
    return 0;
}
