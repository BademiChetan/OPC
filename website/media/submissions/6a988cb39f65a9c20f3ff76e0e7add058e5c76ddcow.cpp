// Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>

// Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)          for(int i=a;i<b;i++)
#define pb                  push_back
#define mp                  make_pair
#define s(n)                scanf("%d",&n);
#define sl(n)               scanf("%lld",&n);
#define sf(n)               scanf("%f",&n);
#define fill(a,v)           memset(a,v, sizeof a);
#define all(x)              x.begin(),x.end()
#define maX(a,b)            (a>b?a:b)
#define miN(a,b)            (a<b?a:b)
void solve()
{
  int n,k,p;
  s(n); s(k);
  p=2;
  for(int i=0;i<n;i++)
   p=(p*p)%k;

   printf("%d\n",p);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
      solve();
    return 0;
}
