#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
using namespace std;
//Macros
#define SIZE(A) ((int)(A.size()))
#define SET(A,x) memset(A,x,sizeof(A));                 //NOTE: Works only for x = 0 and -1. Only for integers.
#define FILL(A,x) fill(A.begin(),A.end(),x)
#define REP(i,N) for(int i=0;i<(int)(N);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REV(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(x)  x.begin(),x.end()
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define EPS 1e-11
#define GI ({int t;scanf("%d",&t);t;})                  //NOTE: Don't comma separate two inputs.
#define GL ({long long t;scanf("%lld",&t);t;})          //NOTE: Don't comma separate two inputs.
#define GF ({double t;scanf("%lf",&t);t;})              //NOTE: Don't comma separate two inputs.
#define MP make_pair
#define PB push_back
#define gcd(a,b) __gcd(a,b)                             //NOTE: Both the arguments should be of the same type.
#define nbits(n) __builtin_popcount(n)                  //NOTE: Works only for int. Write your own function for long long :-/
#define MOD 1000000007
#define FIX(a) (((a)%MOD+MOD)%MOD)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define SUBMIT false                                    //NOTE: Set this to true before submitting
#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
#define   debug1(A,N)           if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,N)cout<<A[i]<<" ";cout<<"\n";}
#define   debug2(A,R,C)         if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,R){REP(j,C){cout<<A[i][j]<<" ";}cout<<"\n";}}

//Main code starts here

#define MAXN 100005
#define MAXL 22       // few more than log for safety :  ceil( log n ) + 1 is the actual needed  

string s;
int n,inc,i,j,ub;
int A[MAXL][MAXN];
int M[MAXN][MAXL];
int Log[MAXN];
int B[MAXN], lcp[MAXN];
int ind, k, pos;

struct sub
{
	int x;
	int y;
	int pos;
};

bool cmp ( sub i , sub j )
{
	if( i.x != j.x )
		return i.x < j.x ;
	return i.y < j.y;
}

int LCP(int x, int y)               // haven't tried this : don't know if it works
{
	int k, ret = 0;
	if (x == y) return n - x;
	for (k = ub; k >= 0 && x < n && y < n; k-- )
		if (A[k][x] == A[k][y])
			x += 1 << k, y += 1 << k, ret += 1 << k;
	return ret;
}

void sparsetable()
{
	int i, j;
	int N = n;
	for (i = 0; i < N; i++)
	{
		M[i][0] = i;
		//cout<<M[i][0]<<" ";
	}
	//cout<<endl;
	for (j = 1; 1 << j <= N; j++)
	{
		for (i = 0; i + (1 << j) - 1 < N; i++)
		{
			if (lcp[M[i][j - 1]] < lcp[M[i + (1 << (j - 1))][j - 1]])
				M[i][j] = M[i][j - 1];
			else
				M[i][j] = M[i + (1 << (j - 1))][j - 1];
			//cout<<M[i][j]<<" ";
		}
		//cout<<endl;
	}
}  

int rmq(int i, int j)
{
	int k = Log[j-i+1];
	if(lcp[M[i][k]] <= lcp[M[j-(1<<k)+1][k]])
		return M[i][k];
	return M[j-(1<<k)+1][k];
}


int main()
{
	int t = GI;
	while(t--)
	{
		sub L[MAXN];
        cin >> n ;
		cin >> s;

		for(i = 0 ; i < n ; i++)       
			A[0][i] = s[i] - 'a' ;
		if( n == 1 ) A[0][0] = 0 ;      // so that suffix array for h is 0 and not 7

		for(i = 1 , inc = 1 ; inc < n ; i++, inc<<=1)
		{
			for(j = 0 ; j < n ; j++)
			{
				L[j].x = A[i-1][j];
				L[j].y = ( j + inc < n ) ? A[i-1][j+inc] : -1000;
				L[j].pos = j;
			}
			sort( L , L + n , cmp );
			for(j = 0 ; j < n ; j++)
			{
				if( j == 0 )
					A[i][L[j].pos] = 0;
				else
				{
					if( L[j].x == L[j-1].x && L[j].y == L[j-1].y )
						A[i][L[j].pos] = A[i][L[j-1].pos] ; 
					else
						A[i][L[j].pos] = j;
				}
			}
		}
		ub = i-1;  
		//for(int i = ub ; i <= ub ; i++)
		//{
		//	for(int j = 0 ; j < n ; j++)
		//		cout<<A[i][j]<<" ";
		//	cout<<endl;
		//}

		for(int i = 0 ; i < n ; i++)
			B[A[ub][i]] = i ;

		for(int i = 0 ; i < n - 1; i++)
			lcp[i] = LCP(B[i], B[i+1]);
		lcp[n-1] = 0;

		//REP(i, n)
		//	cout<<lcp[i]<<" ";
		//cout<<endl;
		//cout<<"RMQ table:\n";
		for(int i = 1 ; i < MAXN ; i++)
			Log[i] = log2(i);
		sparsetable();

		int t1 = GI;
		while(t1--)
		{
			ind = GI ; k = GI;
			assert(ind + k - 1 < n);
			assert(k >= 1 && n >= 1 && ind >= 0);

			pos = A[ub][ind];
			//cout<<"Position is: "<<pos<<endl;
			int lo, hi, ans = 0, cnt1 = 0, cnt2 = 0;
			if(lcp[pos] < k)
				cnt1 = 1;
			else
			{
				int lb = pos;
				int ub = n - 1;
				hi = pos;
				assert(lb <= ub);
				while(lb <= ub){
					int mid = (lb + ub) / 2;
					if(lcp[rmq(lb, mid)] < k)
						ub = mid - 1;
					else
					{
						hi = mid;
						lb = mid + 1;
					}
				}
				cnt1 = hi - pos + 2;
			}
			//cout<<"High count is: "<<cnt1<<endl;

			if(pos == 0 || lcp[pos-1] < k)
				cnt2 = 0;
			else
			{
				int lb = 0;
				int ub = pos - 1;
				assert(lb <= ub);
				lo = pos - 1;
				while(lb <= ub){
					int mid = (lb + ub) / 2;
					if(lcp[rmq(mid, ub)] < k)
						lb = mid + 1;
					else
					{
						lo = mid;
						ub = mid - 1;
					}
				}
				cnt2 = pos - lb; 
			}
			//cout<<"Low count is: "<<cnt2<<endl;
			ans = cnt1 + cnt2;
			cout<<ans<<endl;
		}
	}
	return 0;
}

