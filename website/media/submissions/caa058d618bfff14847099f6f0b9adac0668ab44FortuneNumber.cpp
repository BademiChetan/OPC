#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 1

using namespace std;

typedef long long ll;

vector<int> primes;
bitset<50000> bs;

void init()
{
  bs.reset();
  bs.flip();
  bs.set(1,false);
  for(ll i = 2; i <= 45000; i++)
  {
    if(!bs.test((size_t)i)) continue;
    primes.push_back((int)i);
    for(ll j = i*i; j <= 45000 ; j+= i)
    {
      bs.set((size_t) j, false);
    }
  }
}

vector<int> primeFactor(int x)
{
  vector<int> ret;
  EACH(primes,it)
  {
    int y = *it;
    if(x % y != 0) continue;
    ret.push_back(y);
    while(x % y == 0) x /= y;
  }
  if(x > 1) ret.push_back(x);
  return ret;
}

int phi(int x)
{
  vector<int> v = primeFactor(x);
  int ret = x;
  EACH(v,it)
  {
    int y = *it;
    ret -= ret / y;
  }
  return ret;
}

ll pangkat(ll y,ll k)
{
  ll ret = 1,a = 2;
  while(y > 0)
  {
    while(y % 2 == 0)
    {
      y /= 2;
      a = (a *a) % k;
    }
    ret = (ret * a) % k;
    y--;
  }
  return ret;
}

int main()
{
  int t;
  init();
  scanf("%d",&t);
  while(t--)
  {
    int d,k;
    scanf("%d %d",&d,&k);
    ll ans = pangkat(d,(ll) phi(k));
    ans = pangkat(ans,(ll)k);
    cout << ans << endl;
  }
  return 0;
}
