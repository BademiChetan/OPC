#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <ctime>


using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define istr(S) istringstream sin(S)
#define MP make_pair
#define pb push_back
#define inf 1000000000
#define maxn 1000000

//typedef long long  LL;
//typedef __int64 LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;


int memo[105][105][2];

int solve(int x,int y,int t)
{
	int i,j,ret=0;

	if((x+y)==1) return y ? 1 : 0;
	if(memo[x][y][t]!=-1) return memo[x][y][t];

	for(i=0;i<=2;i++)
	{
		j=2-i;

		if(x<i || y<j) continue;

		int q,nv = (j*y+t)%2;
		if(nv%2)
			q=solve(x-i,y-j+1,!t);
		else
			q=solve(x-i+1,y-j,!t);

	//	printf("%d %d %d %d %d\n",x,y,i,j,q);

		if(q) ret=1;
	}

	return memo[x][y][t]=ret;
}
int main()
{
	int i,j,k,tests,cs=0,n;
	
	scanf("%d",&tests);
	while(tests--)
	{
		scanf("%d",&n);
		int x,y;
		x=y=0;

		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			if(k%2)
				y++;
			else
				x++;
		}
		MEM(memo,-1);

		int ans=solve(x,y,1);

		if(ans)
			puts("WIN");
		else
			puts("LOSE");
	}



	return 0;
} 


