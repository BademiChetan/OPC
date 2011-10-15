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

using namespace std;

#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin();i!=(c).end();i++)
#define REP(i,n) for(long long int i(0);i<(n);i++)
#define dbg(e) cout<<(#e)<<" : "<<e<<endl
#define set(v,i) memset(v,i,sizeof(v))
#define all(x) x.begin(),x.end()
#define sz(x) long long int((x).size())
#define pb  push_back
#define mp make_pair
#define SI ({long long int x;cin>>x;x;})

long long int MOD;

map<long long int,long long int> mem;

long long int find(long long int p)
{
    if(mem[p]) return mem[p];
    long long int &ans=mem[p];
    if(p == 0) return ans=1;
    if(p == 1) return ans=2;
    if(p&1) return ans=(2*(find(p>>1)%MOD)*(find(p>>1)%MOD))%MOD;
    return ans=((find(p>>1)%MOD)*(find(p>>1)%MOD))%MOD;
}
int main()
{
    long long int t=SI;
    while(t--)
    {
        long long int n=SI;
        MOD=SI;
        long long int x= (find(find(n)%MOD)%MOD);
        printf("%ld\n",x);
    }
}
