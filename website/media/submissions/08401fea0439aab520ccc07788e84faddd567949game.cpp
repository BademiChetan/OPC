
#include <cstdio>
#include <iostream>

using namespace std ;

int main () {
  int K ;
  cin >> K ;
  for ( int k = 0 ; k < K ; k ++ ) {
    int n ;
    cin >> n ;
    long long int sum = 0 ;
    for ( int j = 0 ; j < n ; j ++ ) {
      int m ;
      cin >> m ;
      sum += m ;
    }
    sum -= ( ((n-1)*(n)) / 2 )  ;
	 puts(sum%2 == 0 ? "LOSE" : "WIN" ) ;
  }
  return 0 ;
}
