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
	map<int, int>::iterator it, it1, it3;
	
	int T, N, W, i, k, w, v, f, cost, value, newcost, newvalue, oldvalue, j, maxi;
	iscan(T);

	while(T--)
	{
		map<int, int> dp1, dp2, dp3, dp4;
		
		iscan(N);
		iscan(W);

		dp1[0] = 1;
		FOR(i,0,N/2)
		{
			iscan(w);
			iscan(v);
			iscan(f);

			for(it = dp1.begin(); it != dp1.end(); it++)
			{
				cost = (*it).first;
				value = (*it).second;

				if(!value)
					continue;

				//printf("%d:%d\n", cost, value);

				FOR(j,0,f+1)
				{
					newcost = cost + j*w;

					if(newcost > W)
						break;

					oldvalue = dp1[newcost];
					newvalue = value + j*v;

					if(oldvalue == 0)
						dp2[newcost] = newvalue;
					else
						dp2[newcost] = (oldvalue < newvalue ? oldvalue : newvalue);
				}
			}
/*
			printf("%d: ", k);
			for(it = dp2.begin(); it != dp2.end(); it++)
				printf("%d:%d ", (*it).first, (*it).second);
			printf("\n");
*/
			dp1 = dp2;
			dp2.clear();
		}

		dp3[0] = 1;
		for(; i<N; i++)
		{
			iscan(w);
			iscan(v);
			iscan(f);

			for(it = dp3.begin(); it != dp3.end(); it++)
			{
				cost = (*it).first;
				value = (*it).second;

				if(!value)
					continue;

				//printf("%d:%d\n", cost, value);

				FOR(j,0,f+1)
				{
					newcost = cost + j*w;

					if(newcost > W)
						break;

					oldvalue = dp3[newcost];
					newvalue = value + j*v;

					if(oldvalue == 0)
						dp4[newcost] = newvalue;
					else
						dp4[newcost] = (oldvalue < newvalue ? oldvalue : newvalue);
				}
			}

/*			printf("%d: ", k);
			for(it = dp4.begin(); it != dp4.end(); it++)
				printf("%d:%d ", (*it).first, (*it).second);
			printf("\n");
*/
			dp3 = dp4;
			dp4.clear();
		}

		maxi = -1;
		for(it1 = dp1.begin(); it1 != dp1.end(); it1++)
		{
			for(it3 = dp3.begin(); it3 != dp3.end(); it3++)
			{
				if((*it1).first + (*it3).first > W)
					break;

				if(maxi < (*it1).second + (*it3).second)
					maxi = (*it1).second + (*it3).second;
			}
		}

		printf("%d\n", maxi-2);
	}

	return 0;
}
