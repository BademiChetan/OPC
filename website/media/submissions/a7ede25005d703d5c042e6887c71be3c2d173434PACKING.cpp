#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int,int> PII;
typedef long long LL;
#define MAXW 10000000
#define MAXN 150
int dp[MAXW+10];
pair<int,int> S[MAXN+10];

int main() {
    int T;
    scanf("%d", &T);
    while(T--)
    {
    	int N, W;
    	scanf("%d %d", &N, &W);
    	memset(dp, 0, sizeof dp);
    	
    	int sz = 0;
    	for(int i=0;i<N;i++)
    	{
    		int w, v, f;
    		scanf("%d %d %d", &w, &v, &f);
    		for (int i = 1; f >= i; f -= i, i <<= 1)
    		S[sz++] = make_pair(w * i, v * i);
            if (f > 0)
            S[sz++] = make_pair(w * f, v * f);
        }
        sort(S, S+sz);
       	int tot = 0;
       	int ans = 0;
       	for(int i=0;i<sz;i++)
       	{
       		int w = S[i].first, v = S[i].second;
       		tot += w;
            for(int j = min(tot, W); j >= w; --j)
            {
            	dp[j] = max(dp[j], dp[j - w] + v);
            	ans = max(ans, dp[j]);
            }
        }
        printf("%d\n", ans);
	}
	return 0;
}
