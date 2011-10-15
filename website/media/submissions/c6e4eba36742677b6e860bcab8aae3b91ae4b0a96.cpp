
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

const int MOD = 1000003;
const int MAX = 50005;

char text[MAX]; long long key[MAX]; int N, sa[MAX], rank[MAX], *lcp=(int*)key;
struct Cmp { bool operator()(int i, int j) const { return key[i]<key[j]; } };
void build() {
	for (int i = 0; i < N; i++) { sa[i] = i; key[i] = text[i]; }
	sort(sa, sa+N, Cmp());
	for (int K = 1; ; K *= 2) {
		for (int i = 0; i < N; i++)
			rank[sa[i]] = i>0 && key[sa[i-1]]==key[sa[i]] ? rank[sa[i-1]] : i;
		if (K >= N) break;
		for (int i = 0; i < N; i++)
			key[i] = rank[i] * (N+1LL) + (i+K < N ? rank[i+K]+1 : 0);
			sort(sa, sa+N, Cmp());
	}
	
	/*for (int i = 0, k = 0; i < N; i++) {
		if (k > 0) k--;
		if (rank[i] == N-1) { lcp[N-1] = -1; k = 0; continue; }
		int j = sa[rank[i]+1];
		while (text[i+k] == text[j+k]) k++;
		lcp[rank[i]] = k;
	}*/
}

LL hfunc[MAX];
int H[MAX];

void preComp()
{
	hfunc[0] = 1;
	FOR(i, 1, 50001)
	{
		hfunc[i] = hfunc[i-1] * 256;
		if(hfunc[i] >= MOD) hfunc[i] %= MOD;
	}
}


int mismatchPos(int a, int b, int l)
{
	int lo, hi, mid;
	lo = 0;
	hi = min(l, N-b);
	int d1 = N-a, d2 = N-b;
	int pos = -1;
	do
	{
		mid = (lo+hi)/2;
		int t1 = H[a] - H[a+mid];
		if(t1 < 0 ) t1 += MOD;
		int t2 = H[b] - H[b+mid];
		if(t2 < 0 ) t2 += MOD;
		if(d1>d2)
		{
			t2 = (t2*hfunc[d1-d2])%MOD;
		}
		else if(d2>d1)
		{
			t1 = (t1*hfunc[d2-d1])%MOD;
		}
		if(t1!=t2) hi = mid - 1;
		else if(t1==t2)
		{
			lo = mid+1;
			pos = max(pos, mid);
		}
	}while(hi>=lo);
	return pos;
}

int q;
void solve()
{
	//mismatchPos(4, 1, 1);
	int a,b;
	int lo, hi, mid;
	while(q--)
	{
		S("%d%d", &a, &b);
		
		lo = 0;
		hi = N-1;

		int LB = INF;
		int UB = -1;
		do
		{
			mid = (lo+hi)/2;
			int t1;
			t1 = mismatchPos(a, sa[mid], b);
			if(t1==b)
			{
				hi = mid - 1;
				LB = min(LB, mid);
			}
			else
			{
				if( text[a+t1] <= text[sa[mid]+t1])
				{
					LB = min(LB, mid);
					hi = mid - 1;
				}
				else
				{
					lo = mid + 1;
				}
			}
		}while(hi>=lo);

		lo = 0;
		hi = N-1;
		UB = N;
		do
		{
			mid = (lo+hi)/2;
			int t1 = mismatchPos(a, sa[mid], b);
			if(t1==b)
			{
				lo = mid + 1;
			}
			else
			{
				if( text[a+t1] < text[sa[mid]+t1])
				{
					hi = mid-1;
					UB = min(UB, mid);
				}
				else
				{
					lo = mid+1;
				}
			}
		}while(hi>=lo);
		//if(UB==-1) UB = N;


		P("%d\n", UB-LB);
	}
}

int main(int argc, char** argv)
{
	preComp();
	int t; S("%d", &t);
	while(t--)
	{
		S("%d %s %d", &N, text, &q);
		build();
		H[N-1] = text[N-1];
		FORD(i, N-2, 0)
		{
			H[i] = H[i+1] + (text[i]*hfunc[N-i-1])%MOD;
			if(H[i] >= MOD) H[i] -= MOD;
		}
		solve();
	}
	return 0;
}
