#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin();i!=(c).end();i++)
#define dbg(e) cout<<(#e)<<" : "<<e<<endl
#define REP(i,n) for(int i=0;i<(n);i++)
#define set(v,i) memset(v,i,sizeof v)
#define all(x) x.begin(),x.end()
#define sz(x) int((x).size())
#define pb  push_back
#define mp make_pair

typedef long long LL;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int N, sum = 0, x;
        scanf("%d", &N);
        REP(i,N) scanf("%d",&x), sum += x;
        bool win = false;
        if((sum - (N *(N-1) / 2)) % 2 == 0) win = true;
        if(win) printf("LOSE\n");
        else printf("WIN\n");
    }
}
