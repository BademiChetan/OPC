#include<iostream>
#include<cstdio>
#define s(n)          scanf("%d",&n)
using namespace std;
#define ll long long 

int n, mod;
const int a = 2, e = 2;
int primes[256];
int expo(int a, int e, const int MOD) {
    int r = 1;
    while (e > 0) {
        if (e&1) {
            r = (r * (ll)a) % MOD;
        }
        a = (a * (ll)a) % MOD;
        e >>= 1;
    }
    return r;
}

int main(int argc, char** argv) {
	int runs; s(runs);
    while (runs-- > 0) {
        s(n); s(mod);
        int tmp = mod; int psz = 0;
        for (int i=3; i*i <= tmp; i++) {
            bool in = 0;
            while (tmp%i == 0) {
                tmp /= i; in = 1;
            }
            if (in) primes[psz++] = i;
        }
        if (tmp > 1) primes[psz++] = tmp;
        int phi = mod;
        for (int i=0; i < psz; i++) {
            
            phi /= primes[i];
            phi *= primes[i] - 1;
            //cout << primes[i] << " and " << phi << endl;
        }
        int z = expo(2, n, phi);
        int y = expo(2, z, mod);
        printf("%d\n", y);
    }
	return 0;
}
