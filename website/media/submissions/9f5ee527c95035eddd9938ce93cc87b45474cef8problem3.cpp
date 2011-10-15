#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef vector <int> vi;

#define INF 2000000000
#define MAXN 1000000
#define PI 3.14159265

#define FOR(i,a,n) for(int i=a,_n=n; i<_n; ++i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

int n, k;

LL f(LL x, LL bb){
   if ( x == 0 ) return 1LL;
   if ( x == 1 ) return 2LL;
   LL ret = f(x/2, bb) % bb;

   if ( x % 2 == 0 ) return (ret * ret)%bb;
   else return (((ret*ret)%bb)*2)%bb;     
             
}

bool isprime[MAXN+5];
int prime[MAXN];
int cnt = 0;

void sieve(){
     memset(isprime, true, sizeof isprime);
     isprime[0] = isprime[1] = false;
     
     for (int i=2; i*i <= MAXN; ++i){
         if (isprime[i]) for (int j=i*i; j<=MAXN; j+=i) isprime[j] = false;    
     }     
     
     FOR (i, 2, MAXN) if ( isprime[i] ) prime[cnt++] = i;
}

set <int> pfactor (int x){
   set <int > ret;
   int idx = 0; int div = prime[idx];
   
   while ( x != 1 && (div*div) <= x ){
         while ( x % div == 0 ){
               x /= div;
               ret.insert(div);     
         }
         div = prime[++idx];      
   }           
   
   if ( x != 1 ) ret.insert(x);
   
   return ret;
}

int main(){
    sieve();
    int t; scanf("%d", &t);
    
    while (t--){
          scanf("%d %d", &n, &k);
          
          int aa = k;
          //find phi k
          set <int> pf = pfactor(k);
          FOREACH (it, pf) k = k - k/(*it);        
       
          LL x = f(n, k);
          LL ret = f(x, aa);
          
          printf("%lld\n", ret);     
    }
    return 0;
}
