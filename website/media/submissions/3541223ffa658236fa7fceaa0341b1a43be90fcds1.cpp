#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;

#define db(x) cout << (#x) << " = " << x << endl;
#define mp make_pair
#define sz size()
#define FOR(i,x,y) for(int i=x; i<=y; i++)
#define FORN(i,n) FOR(i,0,n-1)
#define clr(x) memset(x,0,sizeof(x));
#define re return
#define pb push_back
#define pf printf
#define sf scanf
#define GI ({int new_input;scanf("%d",&new_input);new_input;})

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    #ifdef PC
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    #endif
    
    int T;
    cin >> T;
    while(T--) {
		int A,B;
		cin >> A >> B;
		int t = max(A-B,B-A);
		if(A > t || B > t)
			cout << t << endl;
		else
			cout << (A+B) << endl;
	}
    re 0;
}
