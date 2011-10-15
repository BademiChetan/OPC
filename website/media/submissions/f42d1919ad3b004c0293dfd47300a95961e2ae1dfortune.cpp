#include<iostream>
using namespace std;

int main() {
long int t,n,k,result,base;
cin >> t;		// number of test cases.
for(long int i=0;i<t;i++) {
cin >> n >> k;
result=1;
base=2;
for(long int i=0;i<n;i++) base=(base*base)%k;
result=(result*base)%k;
cout << result << endl;
}
}
