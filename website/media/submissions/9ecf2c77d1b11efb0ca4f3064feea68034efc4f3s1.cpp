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
	
	//FORN(i,16) {
	//FORN(j,16) {
		int A,B,ans = 0;
		cin >> A >> B;
		//A = i; B = j;
		int t = 1;
		while((t*2 <= A) || (t*2 <= B)) 
			t *= 2;
		
		while(t > 0) {
			//db(t) 
			if(A >= t && B >= t) {
				A -= t; B -= t;
			}
			else if(A >= t) {
				A -= t; ans += t;
			}
			else if(B >= t) {
				B -= t; ans += t;
			}
			//db(A) db(B) db(ans) cout << "\n\n";
			t /= 2;
		}
		cout << ans <<endl;
	
	}
	// cout << endl;	}
    re 0;
}
