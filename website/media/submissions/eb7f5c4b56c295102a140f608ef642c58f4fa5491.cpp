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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SZ(x) ((int)(x).size())
#define FORV(i,x) FOR(i,0,SZ(x))  
#define DBG(x) cout<<(#x)<<" : "<<(x)<<endl
#define PB push_back
#define ALL(x) x.begin(),x.end()

#define ACC(x) accumulate(ALL(x)) 
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define ROFE(i,a,b) for(int i=(b);i>=(a);i--)
#define MP make_pair
#define MAX 1000010
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define PI pair<int,int>
#define PD pair<double,double>
#define F first
#define S second 
#define LL long long
#define ULL unsigned long long

/****************************CODE STARTS HERE***************************************/

int color[1000010];

void swap(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
int main()
{
	int cases,x,y;
	scanf("%d",&cases);
	while(cases--)
	{
		FOR(i,0,MAX) color[i]=i;
		scanf("%d %d",&x,&y);
		FOR(i,0,y-x+1)
			swap(color[i],color[i+x]);
		printf("%d\n",color[y]);
	}
	return 0;
}