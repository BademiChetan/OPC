//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define mp						 	make_pair
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define ss(n) 						scanf("%s",n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)
#define DREP(a)						sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)				lower_bound(all(arr),ind)-arr.begin())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;





const int N = 50005;
int str[N]; //input
int rank[N], pos[N]; //output
int cnt[N], next[N]; //internal
bool bh[N], b2h[N];

// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b)
{
	return str[a] < str[b];
}

void suffixSort(int n)
{
	for (int i=0; i<n; ++i)    pos[i] = i;
	sort(pos, pos + n, smaller_first_char);	 //{pos contains the list of suffixes sorted by their first character}

	for (int i=0; i<n; ++i)
	 {
		bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
		  b2h[i] = false;
	 }

	for (int h = 1; h < n; h <<= 1)
	 {
		  //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
		int buckets = 0;
		for (int i = 0, j; i < n; next[i] = j, i = next[i], buckets ++)
		  {
			cnt[i] = 0;
			rank[pos[i]] = i;
			for (j = i + 1; j < n && !bh[j]; j++)
					rank[pos[j]] = i;
		  }
		if (buckets == n) break; //{suffixes are separted in buckets containing strings starting with the same h characters}

		cnt[rank[n - h]]++;
		b2h[rank[n - h]] = true;
		for (int i = 0; i < n; i = next[i])
		  {
			for (int j = i; j < next[i]; ++j)
			   {
					int s = pos[j] - h;
					if (s >= 0)
					{
						int head = rank[s];
						rank[s] = head + cnt[head]++;
						b2h[rank[s]] = true;
					}
			   }
			for (int j = i; j < next[i]; ++j)
			   {
					int s = pos[j] - h;
					if (s >= 0 && b2h[rank[s]])
						for (int k = rank[s]+1; !bh[k] && b2h[k]; k++) 
b2h[k] = false;
			   }
		  }
		for (int i=0; i<n; ++i)
		  {
			pos[rank[i]] = i;
			bh[i] |= b2h[i];
		  }
	 }
	for (int i=0; i<n; ++i)
		rank[pos[i]] = i;
}
// End of suffix array algorithm



// Begin of the O(n) longest common prefix algorithm
int height[N];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0

void getHeight(int n)
{
	for (int i=0; i<n; ++i) rank[pos[i]] = i;
	height[0] = 0;
	for (int i=0, h=0; i<n; ++i)
	 {
		if (rank[i] > 0)
		  {
			int j = pos[rank[i]-1];
			while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
			height[rank[i]] = h;
			if (h > 0) h--;
		  }
	 }
}

int fwdrmq[17][N];
int bwdrmq[17][N];

void rmq(int n)
{
	for(int i = 0; i < n; i++)
		fwdrmq[0][i] = bwdrmq[0][i] = height[i];
	
	for(int stp = 1, len = 2; stp < 17; stp++, len<<=1)
	{
		for(int i = 0; i < n; i++)
		{
			int b = i - (len>>1);
			int f = i + (len>>1);
			
			if(b >= 0)
				bwdrmq[stp][i] = min(bwdrmq[stp-1][i], bwdrmq[stp-1][b]);
			else 
				bwdrmq[stp][i] = bwdrmq[stp-1][i];
			
			if(f < n)
				fwdrmq[stp][i] = min(fwdrmq[stp-1][i], fwdrmq[stp-1][f]);
			else 
				fwdrmq[stp][i] = fwdrmq[stp-1][i];
		}
	}
}

/*Main code begins now */
int testnum;
int n;
int q;
int m, k;
char temp[1<<16];

void preprocess()
{

}

void solve()
{
	suffixSort(n);
	getHeight(n);
	rmq(n);
	
	s(q);
	for(int i = 0; i < q; i++)
	{
		s(m);
		s(k);
		
		int rnk = rank[m];
		int lo, hi;
		lo = rnk;
		for(int stp = 16; stp >= 0; stp--)
			if(lo >= 0 && bwdrmq[stp][lo] >= k)
				lo = max(-1, lo-(1<<stp));
		
		hi = rnk+1;
		for(int stp = 16; stp >= 0; stp--)
			if(hi < n && fwdrmq[stp][hi] >= k)
				hi = min(n, hi+(1<<stp));

		hi--;
		int ans = hi - lo + 1;
		printf("%d\n", ans);
	}
}

bool input()
{
	s(n);
	scanf("%s", temp);
	
	for(int i=0;i<n;i++)
		str[i]=temp[i]-'a';
		
		
	return true;
}


int main()
{
	preprocess();
	int T;
	s(T);
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}


