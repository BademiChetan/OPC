#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <cassert>

#define llu             long long unsigned int
#define lli             long long int
#define MOD             100000007
#define SI(i)           scanf("%d", &i)
#define SF(i)           scanf("%f", &i)
#define SD(i)           scanf("%lf", &i)
#define SLU(i)          scanf("%llu", &i)
#define SL(i)           scanf("%lld", &i)
#define SS(i)           scanf("%s", &i)
#define SC(i)           scanf("%c", &i)
#define PI(i)           printf("%d", i)
#define PD(i)           printf("%lf", i)
#define PL(i)           printf("%lld", i)
#define PLU(i)          printf("%llu", i)
#define PF(i)           printf("%f", i)
#define PS(i)           printf("%s", i)
#define PC(i)           printf("%c", i)
#define PT(i)           printf(i)
#define NL              printf("\n")
#define SP              printf(" ")
#define TAB             printf("\t")

#define REP(i,n)        for(int i = 0; i < n; i++)
#define FOR(i,a,b)      for(int i = a; i <= b; i++)
#define FORR(i,n)       for(int i = n-1; i >= 0; i--)

using namespace std;

bool isPrime[100000];
int cnt;
int Primes[100000];

void Pre(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i <= 320; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j <= 100000; j += i){
            isPrime[j] = false;
        }
    }
    cnt = 0;
    for(int i = 0; i < 100000; i++){
        if(isPrime[i])
            Primes[cnt++] = i;
    }
}

int Phi(int n){
    int ret = n;
    int i = 0;
    while(i < cnt && n > 1){
        if(n % Primes[i] == 0){
            ret = ret/Primes[i];
            ret = ret *(Primes[i]-1);
            while(n % Primes[i] == 0){
                n= n/Primes[i];
            }
        }
        i++;
    }
    if(n > 1){
        ret = ret/ n;
        ret = ret*(n-1);
    }
    return ret;
}

int Pow(int pow, int modValue){
    if(pow == 0) return 1;
    long long int x = 2;
    long long int r = 1;
    while(pow != 1){
        if(pow&1){
            r = (r * x) % modValue;
        }
        pow = pow >> 1;
        x = (x * x) % modValue;
    }
    r = (r * x) % modValue;
    return r;
}

int main(){
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    Pre();
    int T;
    SI(T);
    int N,K;

    while(T--){
        SI(N);
        SI(K);

        int V = Phi(K);
        PI(Pow(Pow(N,V),K));NL;
    }
}
