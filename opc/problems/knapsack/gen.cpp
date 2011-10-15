// Author: Chetan Bademi
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
using namespace std;
//Macros
#define SIZE(A) ((int)(A.size()))
#define MSET(A,x) memset(A,x,sizeof(A));
#define FILL(A,x) fill(A.begin(),A.end(),x)
#define REP(i,N) for(int i=0;i<(int)(N);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REV(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(x)  x.begin(),x.end()
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define EPS 1e-12
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({long long t;scanf("%lld",&t);t;})
#define GF ({double t;scanf("%lf",&t);t;})
#define bitCount(n) __builtin_popcount(n)
#define MOD 1000000007
#define fix(a) (((a)%MOD+MOD)%MOD)
typedef long long LL;
typedef unsigned long long ULL;
#define SUBMIT false 
#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
//////////////////////////////////////////////////////////// Code written in the contest follows ////////////////////////////////////////////////////////
int main(){
    int tests = 10 ;
    cout << tests << endl; 
    while ( tests -- ) {
        int n = 10 ; 
        int w = rand() % 9000000 + 1000000 ; 
        cout << n << ' ' << w << endl; 
        REP(i,n) {
            cout <<   ( rand() % w ) / 30 + 1 << ' ' << rand() % 1000000 + 1 << ' ' << rand() % 12 + 4  << endl; 
        }
        
    }
	return 0;
}


/*  1 <= T <= 10 , 1 <= n <= 10  1 <= w <= 10^7   1 <= W_i <= 10^6   1 <= V_i <= 10^6    1 <= C_i <= 15 */


// That's all folks!