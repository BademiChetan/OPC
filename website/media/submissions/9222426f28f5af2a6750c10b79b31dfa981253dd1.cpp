#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
using namespace std;



int process(int n, int x, int y) {
  int l;
  l = pow(2, n);
  if (y == 1)
    return x;
  if (max(x,y) <= l/2) {
    return process(n-1, x,y);
  } else if (min(x,y) > l/2) {
    return process(n-1, x-l/2, y-l/2);
  } else if (x <= l/2) {
    return process(n, x+l/2, y-l/2);
  } else {
    return process(n-1, x-l/2, y) + l/2;
  }
}

int x, y, n, N,r;

int main() {
  int i;
  cin>>N;
  for (i = 0; i<N;i++) {
  cin>>x>>y;
  x++;
  y++;
  n = (int)(log(max(x,y))/(float)log(2));
  //cout<<n<<endl;
  if (pow(2,n) < max(x,y)) {
    n++;
  }
  //cout<<n<<endl;
  r=process(n,x,y);
  cout<<r-1<<endl;
  }
}
