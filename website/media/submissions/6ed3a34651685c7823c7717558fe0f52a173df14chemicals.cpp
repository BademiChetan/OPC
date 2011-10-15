#include<algorithm>
#include<assert.h>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define LL long long int

int N, W;

int main()
{
	map<int, int> dp[12];
	map<int, int>::iterator it;
	
	int T, N, W, i, k, w, v, f, cost, value, newcost, newvalue, oldvalue, j, maxi;
	iscan(T);

	while(T--)
	{
		iscan(N);
		iscan(W);

		dp[0][0] = 1;
		k = 1;

		FOR(i,0,N)
		{
			iscan(w);
			iscan(v);
			iscan(f);

			for(it = dp[k-1].begin(); it != dp[k-1].end(); it++)
			{
				cost = (*it).first;
				value = (*it).second;

				if(cost > W)
					break;

				if(!value)
					continue;

				//printf("%d:%d\n", cost, value);

				FOR(j,0,f+1)
				{
					newcost = cost + j*w;
					oldvalue = dp[k-1][newcost];
					newvalue = value + j*v;

					if(oldvalue == 0)
						dp[k][newcost] = newvalue;
					else
						dp[k][newcost] = (oldvalue < newvalue ? oldvalue : newvalue);
				}
			}

/*			printf("%d: ", k);
			for(it = dp[k].begin(); it != dp[k].end(); it++)
				printf("%d:%d ", (*it).first, (*it).second);
			printf("\n");
*/			
			k++;
		}

		maxi = -1;
		for(it = dp[N].begin(); it != dp[N].end(); it++)
			if((*it).second < W && maxi < (*it).second)
				maxi = (*it).second;

		printf("%d\n", maxi-1);
		
		FOR(i,0,12)
			dp[i].clear();

	}

	return 0;
}
