
/***** Author : Kunal *****/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <cmath>
#include <cstdio>
#include <queue>
#include <list>
#include <stack>
#include <utility>
#include <numeric>
#include <map>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <set>
#include <fstream>

using namespace std;

#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define REP(a,b) for(int a=0;a<b;a++)
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)

#define S scanf
#define P printf

#define LEN(x) ((int)x.length())
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define INF 1000000000

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int, PII> PIII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;

//int d[][2]={{-1,0},{1,0},{0,-1},{0,1}};

int W[11], V[11], F[11];
struct prod
{
	int w, v, f;
};

bool cmp(const prod &a, const prod &b)
{
	if(a.v!=b.v) return a.v < b.v;
	else return a.w < b.w;
}

int main(int argc, char** argv)
{
	int t; S("%d", &t);
	int n;
	LL w;
	prod A[10];
	while(t--)
	{
		S("%d%lld", &n, &w);
		REP(i, n) S("%d%d%d", &A[i].w, &A[i].v, &A[i].f);
		sort(A, A+n, cmp);
		map<LL, LL> M[2];
		int bit = 0;
		vector<LL> Q;
		Q.PB(0);
		LL tmp;
		LL Ans = 0;
		REP(i, n)
		{
			int ct = SZ(Q);
			REP(j, ct)
			{
				REP(k, A[i].f)
				{
					tmp = Q[j]+(k+1)*A[i].w;
					if(tmp > w) break;
					if( !M[bit^1][tmp] ) Q.PB(tmp);
					M[bit^1][tmp] = max(A[i].v*(k+1) + M[bit][Q[j]], M[bit^1][tmp]);
					Ans = max(M[bit^1][tmp], Ans);
				}
			}
			M[bit] = M[bit^1];
			bit^=1;
		}
		P("%lld\n", Ans);
	}
   return 0;
}
