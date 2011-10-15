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

int main(){
    int t; scanf("%d", &t);
    
    while (t--){
          int arr[105];
          int n; scanf("%d", &n);
          int sum = 0;
          FOR (i, 0, n) scanf("%d", &arr[i]), sum += arr[i], sum -= i;
          
          if ( sum % 2 == 0 ) puts("LOSE");
          else puts("WIN");      
    }
    return 0;
}
