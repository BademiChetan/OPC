#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <bitset>

using namespace std;
 
typedef unsigned long long ULL;
typedef long long LL;
typedef vector< int > vi;

#define pb push_back
#define mp make_pair
#define MAX 50

#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LLt;scanf("%lld",&t);t;})
#define SET(x,a) memset(x,a,sizeof(x))
#define INF (int)1e9
#define EPS (double)1e-9
#define fii freopen("ip.txt","r",stdin)
#define fio freopen("out.txt","w",stdout)
LL powmod(int b,long long int p,LL m)
{
    LL r=1;
    for(LL i=(1LL<<62);i;i>>=1)
    {
           r*=r;
           if(m>0) r%=m;
           if(p&i) { r*=b;if(m>0) r%=m;}
    }
    return r;
}
int main()
{
    int t;
    LL a,b;
    cin>>t;
    while(t--)
    {
              cin>>a>>b;
              cout<<powmod(4,a,b)<<endl;
    }
    return 0;
}
