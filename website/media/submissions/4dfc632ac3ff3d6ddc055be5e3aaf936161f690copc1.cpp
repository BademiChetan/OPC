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

LL MOD;
map< int , LL> mem;
LL findpow(int x)
{
    if(mem[x]) return mem[x];
    LL &ans=mem[x];
    if(x==0) return ans=1;
    if(x==1) return ans=2;
    if(x%2)
        return ans=((2%MOD) * (findpow(x/2)%MOD) * (findpow(x/2)%MOD))%MOD;
    return ans=((findpow(x/2)%MOD) * (findpow(x/2)%MOD))%MOD;
}
int main()
{
    int t=SI;
    while(t--)
    {
        mem.clear();
        int n1=SI;
        MOD=SI;
        printf("%ld\n",LL(findpow(findpow(n1)%MOD)%MOD));
    }
}
