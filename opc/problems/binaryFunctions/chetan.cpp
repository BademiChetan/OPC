#include<iostream>
#include<vector>
#define fix(n,m) ( ( n % m + m ) % m  )
using namespace std;
long long fastMultiply(long long a,long long b,long long c){
    if( b == 0 )
        return 1LL % c ;
    long long ans = fastMultiply( a , b / 2 , c ) ;
    ans = fix( ans * ans , c);
    if( b % 2 == 1 )
        ans = fix( ans * a , c );
    return ans ;
}
long long getPhi(long long k){
    long long kk = k ;
    long long ans = k ;
    for ( long long i = 2LL; i*i <= k ; i ++ ){
        if( kk % i == 0 ){
            while ( kk % i == 0 )
                kk /= i ;
            ans -= ans / i ;
        }
    }
    if( kk > 1 )
        ans -= ans / kk ;
    return ans ;
}
int main(){
    int tests;
    long long n,k;
    cin >> tests;
    while(tests--){
        cin >> n >> k ;
        long long phi = getPhi(k);
        long long expo = fastMultiply( 2 , n , phi  );
        long long ans = fastMultiply( 2 , expo , k ) ;
        cout << ans << endl; 
    }
    return 0;
}