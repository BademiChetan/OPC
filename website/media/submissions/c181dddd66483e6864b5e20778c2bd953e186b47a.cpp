#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int T;
long long ret;

void getColor(int sz,int x,int y) {
    if (!sz) return;
    int half = 1 << (sz - 1);
    if (x < half != y < half) ret += half;
    getColor(sz - 1,x % half,y % half);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        int x,y;
        scanf("%d %d", &x, &y);
        ret = 0;
        getColor(20,x,y);
        cout << ret << endl;
    }
}
