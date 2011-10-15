#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include<memory.h>
using namespace std;
#define FORD(i, a, b, c) for(int i=(a); i<(b); i+=(c))
#define FOR(i, a, b) FORD(i,a,b,1)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define SI(x) ((int)x.size())
#define PB push_back
#define MP make_pair
#define ALL(a) a.begin(),a.end()
#define INF 1000000000
#define V vector
#define S string
typedef V<int> VI;
typedef long long LL;


int main()
{
    int t;
    cin>>t;
    while (t--){
        int n;cin>>n;
        int ans = 0;
        REP(i, n){
            int x;
            cin>>x;
            ans+=x;
        }
        ans-=(n-1)*n/2;
        if (abs(ans)%2){
            cout<<"WIN\n";
        }
        else cout<<"LOSE\n";
    }
    return 0;
}
