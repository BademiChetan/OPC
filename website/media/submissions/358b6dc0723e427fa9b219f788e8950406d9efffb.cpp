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

int n,T;

int main() {
//    freopen("b.in.1","r",stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            sum = (sum + x) % 2;
        }
        for (int i = 1; i < n; i++) {
            sum = (sum - i) % 2;
            sum = (sum + 2) % 2;
        }
        int numTurn = (n - 1) % 2;
        if (sum ^ numTurn) printf("LOSE\n"); else printf("WIN\n");
    }
}
