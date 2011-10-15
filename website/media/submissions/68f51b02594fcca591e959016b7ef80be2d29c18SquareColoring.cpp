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
#define MAX 1

using namespace std;

int mat[10][10] = 
{
  {0,1,2,3},
  {1,0,3,2},
  {2,3,0,1},
  {3,2,1,0}
};

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int a,b,d,x,y;
    scanf("%d %d",&a,&b);
    x = a % 4;
    y = b % 4;
    d = abs((a/4) - (b/4));
    printf("%d\n",mat[x][y] + 4 * d);
  }
  return 0;
}
