#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

long long  t, n, k, ans, modd = 1000000007;

long long int findrem(long long int n,long long int k){
  if(n==1){return 2%k;}
  if(n==0){return 0;}
  if(n%2==1){return (2*findrem(n-1,k))%k;}
  long long int m=findrem(n/2,k);
  return (m*m)%k;
}

int main() {
  cin>>t;
  int i;
  for (i = 0; i < t; i++) {
    cin>>n>>k;
    if (k==2 ) {
      ans = findrem(n-1, modd);
    } else {
      ans = findrem(n, modd) + (((k-1)*findrem(n/k, modd))%modd);
      ans /= k;
    }
    cout<<ans%modd<<endl;
  }
}

