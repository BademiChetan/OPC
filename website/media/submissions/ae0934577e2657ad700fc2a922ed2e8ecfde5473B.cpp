#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 120

using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,sums = 0;
    scanf("%d",&n);
    FOR(i,0,n-1)
    {
      int x;
      scanf("%d",&x);
      sums += x;
    }
    sums -= (n+1)*n/2;
    if(sums % 2 == 0) puts("LOSE");
    else puts("WIN");
  }
  return 0;
}
