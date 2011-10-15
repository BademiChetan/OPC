#include<iostream>
#include<vector>
#define MOD 1000000007
#define fix(n) ( ( n % MOD + MOD ) % MOD  )
using namespace std;
int main(){
    int tests;
    long long n,k;
    cin >> tests;
    while(tests--){
        int x , y ;
       cin >> x >> y ;
       cout << ( x ^ y )  << endl ;
    }
    return 0;
}