#include<iostream>
#include<cstdlib>
#define MOD 1000000007
#define fix(n) ( ( n % MOD + MOD ) % MOD  )
using namespace std;
int main(){
    int tests = 100;
    cout << tests << endl ;
    while(tests--){
        int n = rand() % 100 + 1 ;
        cout << n << endl; 
        while( n -- )
            cout << rand() % 100 + 1 << ' ';
        cout  << endl; 
    }
    return 0;
}