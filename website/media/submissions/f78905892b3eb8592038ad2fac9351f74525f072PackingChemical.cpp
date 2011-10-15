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
typedef struct _Chem
{
  int price,val,num;
  _Chem()
  {
    price = val = num = 0;
  }
  _Chem(int a,int b, int c)
  {
    price = a;
    val = b;
    num = c;
  }
  bool operator < (const _Chem & chem) const 
  {
    return (price < chem.price) || (price == chem.price && val > chem.val);
  }
}Chem;

vector<Chem> data;
int n, budget;
int memo[11][10000100];

int f(int ind, int budget)
{
  //cout << ind << " " << budget << endl;
  if(ind == n || budget < data[ind].price) return 0;
  //if(memo[ind][budget] != -1) return memo[ind][budget];
  int ret = 0,c = data[ind].num;
  FOR(i,0,c)
  {
    if(budget < data[ind].price * i) break;
    int res = f(ind+1,budget-data[ind].price * i) + data[ind].val * i;
    ret = max(res,ret);
  }
  return memo[ind][budget] = ret;
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
      data.push_back(Chem(a,b,c));
    }
    n = data.size();
    sort(data.begin(),data.end());
    //memset(memo,-1,sizeof(memo));
    printf("%d\n",f(0,budget));
  }
  return 0;
}
