#include<iostream>
#include<cstdio>
#define MOD 1000000007
#define fix(n) ( ( n % MOD + MOD ) % MOD  )
using namespace std;
int main(){
    int tests;
    cin >> tests;
    while(tests--){
        int n;
        cin >> n ; 
        int s = 0 ;
        int t ;
        for(int i = 0 ; i < n ; i ++ ){
            cin >> t ;
            s += t ;
        }
        s -= ( n * ( n - 1 ) ) / 2 ;
        if( s % 2 != 0 )
            cout << "WIN\n";
        else
            cout << "LOSE\n";
    }
    return 0;
}