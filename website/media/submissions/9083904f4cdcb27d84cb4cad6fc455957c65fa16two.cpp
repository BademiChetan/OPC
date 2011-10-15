#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
typedef pair<int,string> pis;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<int,string> mis;
typedef long long ll;
typedef unsigned long long ull;
typedef queue<int> qi;
template<class T> inline bool between(const T &x, const T &a, const T &b) { return x >= (a<b ? a : b) && x <= (a>b ? a : b); }
#define foreach(var, container) for(typeof((container).begin()) var = (container).begin(); var != (container).end(); ++var)


int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int total = 0;
		int N, k;
		
		cin >> N;
		
		for (int i = 0; i < N; i++)
		{
			cin >> k;
			total += k;
		}
		
		total -= N;
		
		cout << (total % 2 ? "LOSE" : "WIN") << endl; 
		
		
	}
	return 0;
}
