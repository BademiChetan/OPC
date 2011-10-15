#include <cstdio>

typedef long long int LLI;

LLI F(LLI r, LLI k, LLI m)
{
    if (k == 0) {
        return r % m;
    }
    if (!(k & 1)) {
        return (F(F(r, k/2, m), k/2, m) % m);
    } else {
        LLI t = F(F(r, k/2, m), k/2, m) % m;
        return (t * t) % m;
    }
}

int main (void)
{
    LLI T, N, K;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld %lld", &N, &K);
        printf("%lld\n", F(2, N, K));
    }
    return 0;
}
