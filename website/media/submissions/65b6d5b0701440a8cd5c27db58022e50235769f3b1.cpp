#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
long a[4][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
using namespace std;

long find(long x, long y) {
    if (x + y == 0) return 0;
    long i = 1;
    while ((i <= x) || (i <= y)) i *= 4;    
    long j = i / 4;
    return a[x/j][y/j] * j + find(x %j, y % j );
}

int main() {
//    freopen("test.in", "r",stdin);
//    freopen("test.out", "w",stdout);    
	long t,x,y,i,j,k;    
	cin >> t;

	for (i = 0; i < t; i ++) {
		cin >> x >> y;
		cout << find(x,y) << "\n";
	}
}
