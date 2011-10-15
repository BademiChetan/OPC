/*
*	ID : pallab81
* 	PROG : fortune
* 	LANG : C++
* 	2011-09-25-17.31.58 Sunday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;

#define VI vector< int >
#define CI( x ) scanf("%d",&x)
#define CL( x ) scanf("%lld",&x)
#define CD( x ) scanf("%lf",&x )
#define foR(i,st,ed) for(int i = st ; i < ed ; ++i )
#define fo(i,ed) foR( i , 0 , ed )
#define foE(i,st,ed) for(int i = st ; i <= ed ; ++i )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define bip system("pause")
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define f first
#define s second
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )

inline void wait(double seconds) {
    double endtime = clock()+(seconds * CLOCKS_PER_SEC);
    while (clock() < endtime) {
        ;
    }
}
Int N,K;

inline void Read(){
    CL(N);
    CL(K);
}

inline vector<int> find_circle(){
	Int x = 2;
    Int y = K;
    vector< int > vt;
    for(int i=1; i<=10; ++i ){
        int m = x%y;
        int found=0;
        for(int j=0,k=SZ(vt);j<k;++j){
			if( vt[j]==m ){
				found=1;
				break;
			}
		}
		if( found ){
			break;
		}
		else{
			vt.pb(m);
		}
		x*=x;
		//cout<<x<<"\n";
    }
   return vt;
}
inline void Proc(){
    vector< int > vt = find_circle();
    int sz = SZ(vt);
    /*
    fo(i,SZ(vt)){
		cout<<vt[i]<<" ";
	}
	*/
	N+=1;
	int indx = N%sz ? N%sz : N ;
	cout<<vt[indx-1]<<"\n";
}
int main() {
/*	
#ifndef ONLINE_JUDGE
    freopen("in", "rt", stdin);
#endif
*/

    int cases = 1;
    for ( CI(cases) ; cases; --cases) {
        Read();
        Proc();
    }
	
    return 0;
}
