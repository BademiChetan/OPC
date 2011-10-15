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
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define SUBMIT false                                    //NOTE: Set this to true before submitting
#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
#define   debug1(A,N)           if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,N)cout<<A[i]<<" ";cout<<"\n";}
#define   debug2(A,R,C)         if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,R){REP(j,C){cout<<A[i][j]<<" ";}cout<<"\n";}}

//Main code starts here

#define MAXVAL 2000000000

int n, w, v, num, size;
vector<pair<int,int> > A, B;

int main()
{
	int t = GI;
	while(t--)
	{
		A.clear();
		B.clear();
		n = GI; size = GI;
		FOR(i,1,n){
			w = GI; v = GI; num = GI;
			assert( 0 <= w && 0 <= v && 0 <= num ); 
// 			cout<<"Calculating for weight of "<<w<<" for value of "<<v<<endl;
			for(int b = 1, sum = 0 ; ; b *= 2)
			{
				if(sum + b <= num)
				{
// 					cout<<"Added weight of "<<(w * b)<<" and value of "<<(v * b)<<endl; 
					if(i & 1)
						A.push_back(make_pair(w * b, v * b));
					else
						B.push_back(make_pair(w * b, v * b));
					sum += b;
				}
				else
				{
					assert(sum <= num);
					if(sum == num) break;
// 					cout<<"Added weight of "<<(w * (num - sum))<<" and value of "<<(v * (num - sum))<<endl; 
					if(i & 1)
						A.push_back(make_pair(w * (num - sum), v * (num - sum)));
					else
						B.push_back(make_pair(w * (num - sum), v * (num - sum)));
					break;
				}
			}
		}

		vector<pair<int,int> > a, b;
		a.clear() ; b.clear();
		int a1 = A.size();
		int b1 = B.size();

		for(int i = 0 ; i < (1<<a1) ; i++)
		{
			int wsum = 0, vsum = 0;
			for(int j = 0 ; j < a1 ; j++)
			{
				if(i & (1<<j))
					wsum += A[j].first, vsum += A[j].second;
				assert(wsum >= 0 && vsum >= 0 && vsum < MAXVAL);
			}
			a.push_back(make_pair(wsum, vsum));
		}
					
		for(int i = 0 ; i < (1<<b1) ; i++)
		{
			int wsum = 0, vsum = 0;
			for(int j = 0 ; j < b1 ; j++)
			{
				if(i & (1<<j))
					wsum += B[j].first, vsum += B[j].second;
				assert(wsum >= 0 && vsum >= 0 && vsum < MAXVAL);
			}
			b.push_back(make_pair(wsum, vsum));
		}

		b.push_back(make_pair(0,0));
		int sz = a.size();
		int ans = 0;
		//cout<<"Sizes: "<<A.size()<<" "<<B.size()<<" "<<a.size()<<" "<<b.size()<<endl;

		sort(b.begin(), b.end());		
		int s = b.size();

		vector<int> maxval;
		REP(i, s){
			if(i == 0) maxval.push_back(b[i].second);
			else 	   maxval.push_back(max(maxval[i-1], b[i].second));
		}
		REP(i, sz){
			if(a[i].first > size) continue;
			int ub = (int) (upper_bound(b.begin(), b.end(), make_pair(size - a[i].first, MAXVAL)) - b.begin());
			assert(ub <= b.size() && ub >= 1);
			if(ub >= 1)
				ans = max(ans, a[i].second + maxval[ub-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
