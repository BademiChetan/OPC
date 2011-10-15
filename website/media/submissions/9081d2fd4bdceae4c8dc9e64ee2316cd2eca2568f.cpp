#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#define maxn 50005
#define maxk 20
using namespace std;

int T,Q,n;
int A[maxn],B[maxn],Bucket[maxn],newBucket[maxn],BucketCount[maxn],final[maxn],lcp[maxn],f[maxn];
vector<int> init[256];
string s;
int mini[maxn][maxk];

void SuffixArray()
{
     for (int i = 0; i < 256; i++) init[i].clear();
     s += '$';
     n++;
     for (int i = 0; i < n; i++) init[s[i]].push_back(i);
     int last = 0;
     for (int i = 0; i < 256; i++) if (!init[i].empty())
     {
         int first = last;
         for (int j = 0; j < init[i].size(); j++)
         {
             A[last] = init[i][j];  Bucket[init[i][j]] = first;  last++;
         }
     }

     for (int cnt = 1; cnt >> 1 < n; cnt <<= 1)
     {
         memset(BucketCount,0,sizeof(BucketCount));
         for (int i = 0; i < n; i++) if (A[i] >= cnt)
         {
             int index = A[i] - cnt;
             int x = Bucket[index];
             B[x + BucketCount[x]] = index;  BucketCount[x]++;
         }
         for (int i = 0; i < n; i++) if (A[i] >= n - cnt)
         {
             int x = Bucket[A[i]];
             B[x + BucketCount[x]] = A[i];  BucketCount[x]++;
         }

         newBucket[B[0]] = 0;
         for (int i = 1; i < n; i++)
         {
             int pos = newBucket[B[i - 1]];
             if (Bucket[B[i]] != Bucket[B[i - 1]]) pos = i;
             if (B[i] + cnt >= n || B[i - 1] + cnt >= n || Bucket[B[i] + cnt] != Bucket[B[i - 1] + cnt]) pos = i;
             newBucket[B[i]] = pos;
         }

         for (int i = 0; i < n; i++)
         {
             A[i] = B[i];  Bucket[i] = newBucket[i];
         }
     }

     for (int i = 0; i < n; i++) final[A[i]] = i;
     int len = 0;
     for (int i = 0; i < n - 1; i++)
     {
         int pos = final[i],j = A[pos - 1];  len = max(len - 1,0);
         while (i + len < n && j + len < n && s[i + len] == s[j + len]) len++;
         lcp[pos] = len;
     }
     for (int i = 1; i < n; i++) f[i] = lcp[A[i]];

     int k = (int) floor(log(n - 1)/log(2));
     for (int i = 1; i < n; i++) mini[i][0] = lcp[i];
     for (int j = 1; j <= k; j++)
       for (int i = 0; i + (1 << j) - 1 < n; i++)
         mini[i][j] = min(mini[i][j - 1],mini[i + (1 << (j - 1))][j - 1]);
}

int getMin(int x,int y) {
    int k = (int) floor(log(y - x + 1)/log(2));
    return min(mini[x][k],mini[y - (1 << k) + 1][k]);
}

int main()
{
//    freopen("f.in.1","r",stdin);
    scanf("%d\n", &T);
    while (T--) {
        scanf("%d\n", &n);
        cin >> s;
        SuffixArray();

        scanf("%d\n", &Q);
        while (Q--) {
            int first,len;
            scanf("%d %d\n", &first, &len);
            int lower = final[first],upper = final[first];
            int low = 1,high = final[first] - 1;
            while (low <= high) {
                int mid = (low + high)/2;
                if (getMin(mid + 1,final[first]) >= len) {
                    lower = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            low = final[first] + 1;  high = n - 1;
            while (low <= high) {
                int mid = (low + high)/2;
                if (getMin(final[first] + 1,mid) >= len) {
                    upper = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            printf("%d\n", upper - lower + 1);
        }
    }
}
