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
#define MAX 300

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
vector<pii> data;
int n, budget;

bool comp(const pii & a, const pii & b)
{
  double costA = (double) a.second/ (double)a.first;
  double costB = (double)b.second / (double)b.first;
  return costA > costB;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&budget);
    while(n--)
    {
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      FOR(i,0,c-1) data.push_back(pii(a,b));
    }
    sort(data.begin(),data.end(),comp);
    ll sums = 0;
    EACH(data,it)
    {
      if(budget <= 0) break;
      //cout << it->first << " " << it->second << endl;
      if(it->first > budget) continue;
      sums += (ll)it->second;
      budget -= it->first;
    }
    cout << sums << endl;
  }
  return 0;
}
