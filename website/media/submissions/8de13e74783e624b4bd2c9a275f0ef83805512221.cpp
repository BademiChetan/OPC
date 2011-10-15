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
#define MAXP 25
#define MAXN 1000011

int pows[25];
int main() {
	pows[0] = 1;
	for(int i=1;i<MAXP;i++)
	pows[i] = pows[i-1] * 2;

	int T;
	scanf("%d", &T);
	while(T--)
	{
		int X,Y;
		scanf("%d %d", &X, &Y);
		int x = 0, y = 0;
		for(int N=20;N>=0;N--)
		{
			if(Y == 0 || X == 0) break;
			int xx = X - x, yy = Y - y;
			
			if(xx >= pows[N-1] && yy >= pows[N-1]) // 4th
			{
				X -= pows[N-1], Y -= pows[N-1];
			}
			else if(xx >= pows[N-1])
			{
				X -= pows[N-1], Y += pows[N-1];
				y += pows[N-1];
			}
			else if(yy >= pows[N-1])
			{
				y += pows[N-1];
			}
		}
		printf("%d\n", X+Y);
	}
	return 0;
}

