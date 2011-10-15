#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define LL long long
#define SZ(x) ((int) x.size())
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define PII pair<int, int>
#define ALL(a) a.begin(), a.end()
#define FOR(i, a, b) for (i = (a); i < (b); i++)
#define FORD(i, b, a) for (i = (b); i >= (a); i--)
#define FORV(i, a) FOR(i, 0, SZ(a))

using namespace std;

int main()
{
    int t, tt, n, i, j, sum;
    int a[200];
    bool used[200];
    bool found;
    cin >> t;
    FOR(tt,0,t)
    {
        cin >> n;
        sum = 0;
        memset(used,false,sizeof(used));
        FOR(i,0,n)
        {
            cin >> a[i];
            sum += a[i];
        }
        FOR(i,1,n+1)
        {
            sum -= i;
        }
        if (sum % 2 == 1)
            cout << "WIN" << endl;
        else
            cout << "LOSE" << endl;
    }
}

