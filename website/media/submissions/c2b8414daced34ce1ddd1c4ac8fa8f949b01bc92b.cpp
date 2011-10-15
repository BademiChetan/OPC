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

int f[102][102][2];
int n,T;

int win(int numOdd,int numEven,int parity) {
    if (numOdd + numEven < 2) return (numEven);
    if (f[numOdd][numEven][parity] >= 0) return f[numOdd][numEven][parity];

    int &ans = f[numOdd][numEven][parity];
    ans = 0;
    int tmp;
    if (numOdd > 1) {
        tmp = (1 + 1 - parity) % 2;
        int _numOdd = numOdd - 2 + (tmp % 2);
        int _numEven = numEven + (tmp % 2 == 0);
        if (!win(numOdd,_numEven,parity ^ 1)) return ans = 1;
    }
    if (numEven > 1) {
        tmp = (2 + 2 - parity) % 2;
        int _numOdd = numOdd + (tmp % 2);
        int _numEven = numEven - 2 + (tmp % 2 == 0);
        if (!win(_numOdd,_numEven,parity ^ 1)) return ans = 1;
    }
    if (numOdd && numEven) {
        tmp = (1 + 2 - parity) % 2;
        int _numEven = numEven - 1 + (tmp % 2 == 0);
        int _numOdd = numOdd - 1 + (tmp % 2);
        if (!win(_numOdd,_numEven,parity ^ 1)) return ans = 1;
    }
    return ans;
}

int main() {
//    freopen("b.in.1","r",stdin);
    memset(f,-1,sizeof(f));
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int numOdd = 0,numEven = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x & 1) numOdd++; else numEven++;
        }
        if (win(numOdd,numEven,1)) printf("WIN\n"); else printf("LOSE\n");
    }
}
