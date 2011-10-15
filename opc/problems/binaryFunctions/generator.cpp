#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main(){
    int tests = 1000 ; 
    cout << tests << endl; 
    while( tests -- ){
        cout << rand() % 1000000001 << ' ' <<  ((rand() % 100000001)|1LL )<< endl; 
    }
    return 0;
}