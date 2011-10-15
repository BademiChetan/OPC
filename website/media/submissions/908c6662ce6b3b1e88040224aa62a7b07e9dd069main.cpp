#include <iostream>
using namespace std;

int dp[2][10000001];
pair<int,int> v[150];
int n, w, k;

int main()
{
	/*int T; cin >> T;
	while (T--)
	{
		cin >> n >> w;
		k = 0;
		int wi, vi, fi;
		for (int i = 0; i < n; ++i)
		{
			cin >> wi >> vi >> fi;
			for (int j = 0; j < fi; ++j)
				v[k++] = make_pair(vi, wi);
		}
		
		for (int i = 0; i < w+1; ++i)
			if ( i < v[0].second ) dp[0][i] = 0;
			else dp[0][i] = v[0].first;
		
		int x;
		for (int i = 1; i < k; ++i)
		{
			x = i%2;
			dp[x][0] = 0;
			for (int j = 1; j <= w; ++j)
			{
				dp[x][j] = max(dp[x][j-1], dp[1-x][j]);
				if ( j >= v[i].second )
					dp[x][j] = max( dp[x][j], dp[1-x][j-v[i].second]+v[i].first );
			}
		}
		cout << dp[1-(k%2)][w] << endl;
	}*/
}
