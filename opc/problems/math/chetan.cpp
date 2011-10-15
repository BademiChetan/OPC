#include<iostream>
#include<vector>
#define MOD 1000000007
#define fix(n) ( ( n % MOD + MOD ) % MOD  )
using namespace std;
long long fastMultiply(long long a,long long b){
    if( b == 0 )
        return 1LL ;
    long long ans = fastMultiply( a , b / 2 ) ;
    ans = fix( ans * ans);
    if( b % 2 == 1 )
        ans = fix( ans * a );
    return ans ;
}
int main(){
    int tests;
    long long n,k;
    cin >> tests;
    while(tests--){
        cin >> n >> k ;
        long long ans ;
        if ( k == 2 ){
            ans = fastMultiply( 2LL , n - 1 ) ;
        }else{
            ans = fastMultiply( 2 , n / k ) ;
            ans = fix ( ans * ( k - 1 ) ) ;
            ans = fix ( ans + fastMultiply( 2 , n )  ) ;
            ans = fix ( ans * fastMultiply ( k , MOD - 2 ) ) ;
        }
        cout << ans << endl ;
    }
    return 0;
}