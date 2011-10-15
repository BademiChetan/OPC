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
int i,j,n;
for (i=0;i<t;++i)
{
scanf("%d",&n);
int a[n];
int sum=0;
int b=0;
for (j=0;j<n;j++)
{
scanf("%d",&a[j]);
sum=sum+a[j];
}
b=(n)*(n-1)/2;
if((sum-b)%2==0)
cout<<"LOSE";
else
cout<<"WIN";
cout<<endl;
}
system("pause");
return 0;
}
