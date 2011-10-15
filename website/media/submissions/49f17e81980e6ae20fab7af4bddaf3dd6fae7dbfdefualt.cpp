#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <set>
#include <map>
#include <numeric>
#include <ctime>
#include <functional>
#include <queue>

using namespace std;

int main()
{
 int t;
 scanf("%d",&t);
 int i;
 long int j,n,k;
 long int a;
 for (i=0;i<t;++i)
 {a=1;
  cin>>n>>k;
  for (j=0;j<n;j++)
  a=(a<<2)%k;
  cout<<a<<endl;
} 
 
return 0;
}
