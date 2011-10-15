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
#define PI 3.14159265

#define FOR(i,a,n) for(int i=a,_n=n; i<_n; ++i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

int n, k;

LL f(LL x){
   if ( x == 1 ) return 2LL;
   LL ret = f(x/2) % k;

   if ( x % 2 == 0 ) return (ret * ret)%k;
   else return (((ret*ret)%k)*2)%k;     
             
}

int main(){
    int t; scanf("%d", &t);
    
    while (t--){
          scanf("%d %d", &n, &k);
          
          //hitung 2 pangkat n;
          LL x = f(n);
          LL ret = f(x);
          
          printf("%lld\n", ret);     
    }
    return 0;
}
