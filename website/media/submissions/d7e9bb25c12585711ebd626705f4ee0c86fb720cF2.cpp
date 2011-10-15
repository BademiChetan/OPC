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

int stree[1<<17];
const int BASE=1<<16;

void buildTree(int n)
{
	for(int i=0;i<n;i++)
		stree[BASE+i]=height[i];
		
	for(int i=BASE-1;i>=1;i--)
		stree[i] = min(stree[i<<1],stree[(i<<1)+1]);
}

int beg,end;

int lcp(int lo,int hi,int ind)
{
	if(lo>end || hi<beg) return INF;
	if(lo>=beg && hi<=end) return stree[ind];
	return min( lcp(lo, ((lo+hi)>>1), (ind<<1)), lcp(((lo+hi)>>1)+1, hi, (ind<<1)+1) );
}

int lcp(int _beg,int _end)
{
	beg=_beg+1;
	end=_end;
	return lcp(0,BASE-1,1);
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

int begChar[26],endChar[26];

void solve()
{
	suffixSort(n);
	getHeight(n);
	buildTree(n);
	/*
	for(int i=0;i<n;i++)
	{
		printf("%d : %d %d %d\n",i,rank[i],pos[i],height[i]);
	}*/
	
	for(int i=0;i<n;i++)
	{
		endChar[temp[i]-'a'] = i;
	}
	for(int i = n-1; i >= 0; i--)
	{
		begChar[temp[i] - 'a'] = i;
	}
	
	s(q);
	for(int i = 0; i < q; i++)
	{
		s(m);
		s(k);
		
		int lo1, hi1, mid;
		
		int rnk = rank[m];
		
		//left
		lo1 = begChar[temp[m]-'a'], hi1 = rnk;
		while(lo1 < hi1)
		{
			mid = (lo1 + hi1)/2;
			if(lcp(mid,rnk) >= k)
			{
				hi1 = mid;
			}
			else 
				lo1 = mid+1;
			
		}
		
		int lo2, hi2, mid2;
		lo2 = rnk, hi2 = endChar[temp[m]-'a'];
		
		while(lo2 < hi2)
		{
			mid = (lo2 + hi2 + 1)/2;
			if(lcp(rnk,mid) >= k)
			{
				lo2 = mid;
			}
			else 
				hi2 = mid-1;
		}
		
		int ans = hi2 - lo1 + 1;
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


