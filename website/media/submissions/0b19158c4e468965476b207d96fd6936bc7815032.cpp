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
#define MAX 50010
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define PI pair<int,int>
#define PD pair<double,double>
#define F first
#define S second 
#define LL long long
#define ULL unsigned long long

/****************************CODE STARTS HERE***************************************/

int a[110];

int main()
{
	int cases,n,sum;
	scanf("%d",&cases);
	while(cases--)
	{
		sum=0;
		scanf("%d",&n);
		FOR(i,0,n) {scanf("%d",&a[i]);sum+=a[i];}
		sum-=((n)*(n-1))>>1;
		if(sum&1) printf("WIN\n");
		else printf("LOSE\n");
	}
	return 0;
}