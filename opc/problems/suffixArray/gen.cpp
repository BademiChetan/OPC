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
using namespace std;
#define SIZE(A) ((int)(A.size()))
#define REP(i,N) for(int i=0;i<(int)N;i++)
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define TR(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define GI ({int t; scanf("%d",&t);t;})
#define GL ({ long long  t; scanf("%lld",&t);t;})
#define ALL(x)  (x.begin(),x.end())
#define INF 1000000000
#define LINF 1000000000000000000LL
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
int character[]={1,2,4,8,16};
int lengthArray[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
int main(){
    int tests = 10;
    cout <<  tests << endl ;
    while( tests-- ){
        int CHAR = character[tests % 5];
        int n = 50000;
        cout << n << endl; 
        REP(i,n) cout << char( rand() % CHAR + 'a' ) ;
        cout << endl; 
        int q = 50000 ;
        cout << q << endl ;
        while( q -- ){
            int LENGTH = lengthArray[q%14];
            int length  = rand() % LENGTH + 1;
            int index = rand() % ( n - length ) ;
            assert( index < n && index >= 0 );
            assert( length > 0 && length + index < n ) ;
            cout << index << ' ' << length << endl ;
        }
    }
    return 0;
}