/*
Author : OmarEl-Mohandes
PROG   : B
LANG   : C++
*/
#include <map>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <memory.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define REP(i,k,m) for(int i=k;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
#define oo ((int)1e9)
int main()
{
	//freopen("B.in" , "rt" , stdin);
	//freopen("B.out" , "wt" , stdout);
	int t;
	scanf("%d" , &t);
	while(t --){
		int n;
		scanf("%d" , &n);
		int k , r=0;
		while(n--)
		{
			scanf("%d" , &k);
			r += k%2;
		}
		if(r == 0)
			cout << "WIN" << endl;
		else
			cout << "LOSE" << endl;

	}
	return 0;
}

