// Author: Chetan Bademi
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
#define MSET(A,x) memset(A,x,sizeof(A));
#define FILL(A,x) fill(A.begin(),A.end(),x)
#define REP(i,N) for(int i=0;i<(int)(N);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REV(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(x)  x.begin(),x.end()
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define EPS 1e-12
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({long long t;scanf("%lld",&t);t;})
#define GF ({double t;scanf("%lf",&t);t;})
#define bitCount(n) __builtin_popcount(n)
#define MOD 1000000007
#define fix(a) (((a)%MOD+MOD)%MOD)
typedef long long LL;
typedef unsigned long long ULL;
#define SUBMIT false 
#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
//////////////////////////////////////////////////////////// Code written in the contest follows ////////////////////////////////////////////////////////
int n;
vector<vector<int> > powers;
int weight[11],value[11],freq[11],totalWeight;
struct state{
    int value,weight,freq,set;
};
int solve(vector<pair<int,int> > firstSet,vector<pair<int,int> > secondSet){
    int n1 = SIZE(firstSet);
    int n2 = SIZE(secondSet);
    vector<pair<int,int> > firstSetAll,secondSetAll;
    // get first half 
    for( int i = 0 ; i < ( 1 << n1 ) ; i ++ ){
        pair<int,int> t = make_pair(0,0);
        for( int j = 0 ; j < n1 ; j ++ ){
            if( i & ( 1 << j ) ) {
                t.first += firstSet[j].first;
                t.second += firstSet[j].second;
            }
        }
        firstSetAll.push_back(t);
    }
    // get second half 
    for( int i = 0 ; i < ( 1 << n2 ) ; i ++ ){
        pair<int,int> t = make_pair(0,0);
        for( int j = 0 ; j < n2 ; j ++ ){
            if( i & ( 1 << j ) ) {
                t.first += secondSet[j].first;
                t.second += secondSet[j].second;
            }
        }
        secondSetAll.push_back(t);
    }
    // sort second half and get ready for query
    sort(ALL(secondSetAll));
    vector<int> toSearch( 1 << n2 ) ,dp(1 << n2);
    for( int i = 0 ; i < ( 1 << n2 ); i ++ )
        toSearch[i] = secondSetAll[i].first;
    dp[0] = secondSetAll[0].second;
    for( int i = 1 ; i < ( 1 << n2 ); i ++ )
        dp[i] = max(secondSetAll[i].second, dp[i-1] );
//     REP(i,SIZE(toSearch)) cout << toSearch[i] << ' ' ; cout << endl ;
//     REP(i,SIZE(firstSetAll)) cout << '(' << firstSetAll[i].first << ',' << firstSetAll[i].second << ") "; cout << endl; 
//     REP(i,SIZE(secondSetAll)) cout << '(' << secondSetAll[i].first << ',' << secondSetAll[i].second << ") "; cout << endl; 
    // find the answer
    int ans = 0 ;
    for( int i = 0 ; i < ( 1 << n1 ) ; i ++ ){
        if( totalWeight > firstSetAll[i].first ){   
            int index =  ( upper_bound(toSearch.begin(),toSearch.end(),totalWeight - firstSetAll[i].first) - toSearch.begin() ) - 1 ;
//             cout << totalWeight -  firstSetAll[i].first << ' ' << index << ' ' << toSearch[index-1] << endl; 
            if( ans < dp[index] + firstSetAll[i].second )
//                 cout << " new = " << i << endl; 
            ans = max( ans , dp[index] + firstSetAll[i].second ) ;
        }
    }
    return ans ;
}
int main(){
    int tests;
    cin >> tests;
    powers.resize(16);
    powers[1].push_back(1);
    powers[2].push_back(1);
    powers[2].push_back(1);
    for(int i = 3; i <= 15 ; i ++ ){
        int x = i ; 
        for( int j = 1 ; j <= x ; j *= 2 ){
            powers[i].push_back(j);
            x -= j ;
        }
        if( x > 0 )
            powers[i].push_back(x);
    }
//     for( int i = 1 ; i <= 15 ; i ++ ){
//         for( int j = 0 ; j < SIZE(powers[i]) ; j ++ ){
//             cout << powers[i][j] << ' ' ;
//         }
//         cout << endl; 
//     }
    while(tests--){
        cin >> n >> totalWeight; 
        REP(i,n) cin >> weight[i] >> value[i] >> freq[i] ;
        vector<pair<int,int> > firstSet,secondSet;
        for( int i = 0 ; i < n / 2 ; i ++ ){
            REP(j,SIZE(powers[freq[i]])){
                int x = powers[freq[i]][j] ; 
                if ( weight[i] * x > totalWeight )
                    break;
                firstSet.push_back(make_pair( weight[i] * x ,value[i] * x ));
            }
        }
        for( int i = n / 2 ; i < n ; i ++ ){
            REP(j,SIZE(powers[freq[i]])){
                int x = powers[freq[i]][j] ; 
                if ( weight[i] * x > totalWeight )
                    break;
                secondSet.push_back(make_pair( weight[i] * x ,value[i] * x ));
            }
        }
//         REP(i,SIZE(firstSet)) cout << '(' << firstSet[i].first << ',' << firstSet[i].second << ") "; cout << endl; 
//         REP(i,SIZE(secondSet)) cout << '(' << secondSet[i].first << ',' << secondSet[i].second << ") "; cout << endl; 
        cout << solve(firstSet,secondSet) << endl ;
    }
	return 0;
}
// That's all folks!