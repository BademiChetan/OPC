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

string ss[2]={"LOSE","WIN"};
int n_num;
vector< int > num;
inline void Read(){
    CI(n_num);
    num.assign(n_num,0);
    fo(i,n_num){
        CI(num[i]);
    }
}
inline void Proc(){
    if( n_num==1 ){
        cout<<ss[num[0]%2]<<"\n";
    }
    else if( n_num==2 ){
        cout<<ss[ ((num[0]+num[1]+1) %2) ]<<"\n";
    }
    else{
        int sum=num[0];
        for(int i=1;i<n_num;++i){
            sum+=( num[i]+i );
        }
        cout<<ss[ sum%2 ]<<"\n";
    }
}
int main() {
//#ifndef ONLINE_JUDGE
//    freopen("in", "rt", stdin);
//#endif
    int cases = 1;
    for ( CI(cases) ; cases; --cases) {
        Read();
        Proc();
    }

    return 0;
}
