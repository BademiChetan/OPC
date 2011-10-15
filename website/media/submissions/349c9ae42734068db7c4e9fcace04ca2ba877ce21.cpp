#include <cstdio>
#include <algorithm>

using namespace std;

int lg_int (int n)
{
    int ret = 0;
    while (n > 1) {
        ret++;
        n /= 2;
    }
    return ret;
}

int fast_exp (int a, int n)
{
    int ret = 1, t = a;
    while (n > 0) {
        if (n & 1) {
            ret = ret * t;
        }
        n >>= 1;
        t = t * t;
    }
    return ret;
}

int main (void)
{
    int T;
    int X, Y;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &X, &Y);
        //X++; Y++;
        int ans = 0;
        while (X != Y) {
            int r = lg_int(max(X, Y));
            int s = fast_exp(2, r);

            //printf("r = %d; s = %d\n", r, s);

            if (Y >= s && X < s) {
                Y -= s;
                ans += s;
            } else if (X >= s && Y < s) {
                X -= s;
                ans += s;
            } else {
                X -= s;
                Y -= s;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


