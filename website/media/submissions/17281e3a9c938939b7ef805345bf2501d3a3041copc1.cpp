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
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>



#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin();i!=(c).end();i++)
#define REP(i,n) for(int i(0);i<(n);i++)
#define dbg(e) cout<<(#e)<<" : "<<e<<endl
#define set(v,i) memset(v,i,sizeof(v))
#define all(x) x.begin(),x.end()
#define sz(x) int((x).size())
#define pb  push_back
#define mp make_pair
#define SI ({int x;scanf("%d",&x);x;})
using namespace std;
typedef long long int LL;

int main()
{
    int t=SI;
    while(t--)
    {
        int n=SI;
        int s=0;
        for(int i=0;i<n;i++)
        {
            int a=SI;
            s+=a;
        }
        int aa=n*(n-1)/2;
        s-=aa;
        if(s&1) printf("WIN\n");
        else printf("LOSE\n");
    }
}
