/*********************************HEADER FILES************************************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>

using namespace std;

/***************************MACROS TO SHORTEN THE CODE******************************/
#define FOR(i,a,b) for(int  i=(a);i<(b);i++)
#define SZ(x) ((int )(x).size())
#define FORV(i,x) FOR(i,0,SZ(x))  
#define DBG(x) cout<<(#x)<<" : "<<(x)<<endl
#define PB push_back
#define ALL(x) x.begin(),x.end()

#define ACC(x) accumulate(ALL(x)) 
#define FORE(i,a,b) for(int  i=(a);i<=(b);i++)
#define ROFE(i,a,b) for(int  i=(b);i>=(a);i--)
#define MP make_pair
#define MAX 1000010
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define PI pair<int ,int >
#define PD pair<double,double>
#define F first
#define S second 
#define LL long long
#define ULL unsigned long long

/****************************CODE STARTS HERE***************************************/

int  solve(int  x,int  y)
{
	if(x==0) return y;
	int  q=y/x;
	if(q&1) return y-x;
	else return x+y;
}
int main()
{
	int cases,x,y;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d %d",&x,&y);
		if(x&1)
		{
			if(y&1) printf("%d\n",solve(x-1,y)-1);
			else printf("%d\n",solve(x-1,y)+1);
		}
		else
			printf("%d\n",solve(x,y));
	}
	return 0;
}