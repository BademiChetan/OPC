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

vector< pair<int,int> > firstHalf,secondHalf;
vector<int> firstIdx,secondIdx;
int T,n,B;
int cost[12],value[12],num[12];

void attemptFirst(int pos,int totalCost,int totalValue) {
    if (pos >= firstIdx.size()) {
        firstHalf.push_back(make_pair(totalCost,totalValue));
        return;
    }
    int u = firstIdx[pos];
    for (int i = 0; i <= num[u]; i++) attemptFirst(pos + 1,totalCost + cost[u] * i,totalValue + value[u] * i);
}

void attemptSecond(int pos,int totalCost,int totalValue) {
    if (pos >= secondIdx.size()) {
        secondHalf.push_back(make_pair(totalCost,totalValue));
        return;
    }
    int u = secondIdx[pos];
    for (int i = 0; i <= num[u]; i++) attemptSecond(pos + 1,totalCost + cost[u] * i,totalValue + value[u] * i);
}

int main() {
//    freopen("e.in.1","r",stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &B);
        for (int i = 0; i < n; i++) scanf("%d %d %d", &cost[i], &value[i], &num[i]);
        int best = -1;
        long long c1 = -1,total = 1;
        for (int i = 0; i < n; i++) total *= 1LL * (num[i] + 1);
        for (int mask = 0; mask < (1 << n); mask++) {
            long long curOne = 1;
            for (int i = 0; i < n; i++) curOne *= 1LL * (num[i] + 1);
            long long curTwo = total/curOne;
            if (curOne > curTwo) continue;
            if (curOne > c1) {
                c1 = curOne;  best = mask;
            }
        }

        firstIdx.clear();
        firstHalf.clear();
        secondIdx.clear();
        secondHalf.clear();
        for (int i = 0; i < n; i++) if (best & (1 << i)) firstIdx.push_back(i); else secondIdx.push_back(i);
        attemptFirst(0,0,0);
        attemptSecond(0,0,0);

        sort(firstHalf.begin(),firstHalf.end());
        vector< pair<int,int> > thirdPart;
        for (int i = 0; i < firstHalf.size(); i++) {
            while (!thirdPart.empty()) {
                pair<int,int> last = thirdPart[thirdPart.size() - 1];
                if (last.first >= firstHalf[i].first && last.second <= firstHalf[i].second) thirdPart.pop_back(); else break;
            }
            if (!thirdPart.empty()) {
                pair<int,int> last = thirdPart[thirdPart.size() - 1];
                if (last.first <= firstHalf[i].first && last.second >= firstHalf[i].second) continue;
            }
            thirdPart.push_back(firstHalf[i]);
        }

        int ret = 0;
        for (int i = 0; i < secondHalf.size(); i++) {
            pair<int,int> cur = secondHalf[i];
            int low = 0,high = thirdPart.size() - 1;
            while (low <= high) {
                int mid = (low + high)/2;
                if (thirdPart[mid].first + cur.first > B) high = mid - 1; else {
                    low = mid + 1;
                    ret = max(ret,thirdPart[mid].second + cur.second);
                }
            }
        }
        printf("%d\n", ret);
    }
}
