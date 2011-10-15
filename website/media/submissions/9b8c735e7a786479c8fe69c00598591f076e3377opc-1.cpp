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


int solve(int r,int c,int p,int s)
{
	if(p==0) return s;
	int x=r/p , y=c/p;
//	printf("%d %d %d %d\n",r,c,p,s);

	if((x+y)%2)
		return solve(r%p,c%p,p/2,s+p);
	else
		return solve(r%p,c%p,p/2,s);
			
}
int main()
{
	int i,j,k,tests,cs=0,n;
	
	scanf("%d",&tests);
	while(tests--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		int ans=solve(r,c,1048576,0);
		printf("%d\n",ans);
	}



	return 0;
} 


