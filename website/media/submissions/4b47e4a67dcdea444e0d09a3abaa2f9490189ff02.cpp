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
#define MAXN 101
int A[MAXN];

int main() {
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N;
		scanf("%d", &N);
		int sum = 0;
		for(int i=0;i<N;i++)
		{
			scanf("%d", &A[i]);
			sum += A[i];
		}
		int tmp = (N * (N-1))/2;
		int ret = sum - tmp + 1000000;
		printf("%s\n",ret&1?"WIN":"LOSE");
	}
	return 0;
}

