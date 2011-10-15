#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <utility>
#include <cctype>
#include <list>
#include <limits.h>
#include <signal.h>
#include <map>
#include <set>

#define TR(c, i) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++ ) 
#define FOR(i, a, b) for ( i = a; i <= b; i++ )
#define ROF(i, a, b) for ( i = a; i >= b; i-- )
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort( ALL(v) )
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))
#define ABS(a) ((a) < (0) ? (a)*(-1) : (a))
#define SWAP(a, b) typeof(a) T; T=a; a=b; b=T;

using namespace std;
using namespace __gnu_cxx;
/*
inline void S(int &x)
{
	x=0;
        while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
                ch=getchar_unlocked();
                if (ch=='-')
                        sign=-1 , ch=getchar_unlocked();
                else
                        sign=1;
                do
                        x=(x<<3)+(x<<1)+ch-'0';
                while((ch=getchar_unlocked())>='0' && ch<='9');
                x*=sign;
}
*/
int A[1000];
int main()
{
	int T,N,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int odd = 0 ,even = 0;
		for(int i=0;i<N;i++){
			scanf("%d",&x);
			if(x%2 == 0)
				even++;
			else
				odd++;
		}
		if(even == odd)
			puts("LOSE");
		else
			puts("WIN");
	}		
	return 0;
}
